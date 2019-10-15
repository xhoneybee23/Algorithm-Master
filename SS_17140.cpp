#include <iostream>
#include <queue>
using namespace std;

int num[101][101];

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			cin >> num[i][j];
		}
	}

	int cnt = 0;
	int hang = 3, yeol = 3;
	while (num[r][c] != k){
		cnt++;
		if (cnt > 100) break;
		if (hang >= yeol){ // R 연산
			for (int i = 1; i <= hang; i++){
				int n[101] = { 0 }; // 각 숫자마다 등장횟수 저장
				queue<pair<int, int>> tmp; // 연산 결과 저장할 임시 배열
				for (int j = 1; j <= yeol; j++){
					int temp = num[i][j];
					if (temp != 0) n[temp]++;
				}
				int dung = 1; // 등장횟수
				while (dung <= hang){ // 최대 행의 개수까지만 등장 가능 
					for (int k = 1; k <= 100; k++){
						if (n[k] == dung){
							tmp.push(make_pair(k, dung));
						}
					}
					dung++;
				}
				if (yeol < 2*tmp.size()) yeol = 2*tmp.size();
				
				int queue_size = tmp.size();
				int a = 1;
				while (!tmp.empty()){
					int temp_num = tmp.front().first;
					int temp_cnt = tmp.front().second;
					if (2 * a - 1 > 100) break;
					num[i][2 * a - 1] = temp_num;
					if (2 * a > 100) break;
					num[i][2 * a] = temp_cnt;
					tmp.pop();
					a++;
				}
				// 크기가 줄어든 경우가 있음
				for (int b = 2 * queue_size+1; b <= 101; b++) num[i][b] = 0;
			}
		}
		else { // C 연산
			for (int i = 1; i <= yeol; i++){
				int n[101] = { 0 };
				queue <pair<int, int>> tmp;
				for (int j = 1; j <= hang; j++){
					int temp = num[j][i];
					if(temp != 0) n[temp]++;
				}
				int dung = 1;
				while (dung <= yeol){
					for (int k = 1; k <= 100; k++){
						if (n[k] == dung){
							tmp.push(make_pair(k, dung));
						}
					}
					dung++;
				}
				if (hang < 2*tmp.size()) hang = 2*tmp.size();
				int queue_size = tmp.size();
				int a = 1;
				while (!tmp.empty()){
					int tmp_num = tmp.front().first;
					int tmp_cnt = tmp.front().second;
					if (2 * a - 1 > 100) break;
					num[2 * a - 1][i] = tmp_num;
					if (2 * a > 100) break;
					num[2 * a][i] = tmp_cnt;
					tmp.pop();
					a++;
				}
				// 크기가 줄어든 경우가 있음
				for (int b = 2 * queue_size+1; b <= 101; b++) num[b][i] = 0;
			}
		}
	}

	if (cnt <= 100) cout << cnt << endl;
	else cout << -1 << endl;

	return 0;
}
