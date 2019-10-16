#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 시간초과

int map[51][51];
bool check[51][51];
int dist[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<pair<int, int>> possible_loc;
vector<int> temp;

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> map[i][j];
			if (map[i][j] == 2) {
				possible_loc.push_back(make_pair(i, j));
				check[i][j] = true;
			}
			else if (map[i][j] == 1){
				check[i][j] = true;
			}
		}
	}
	// 2의 개수 중 M개 고르기
	vector<int> tmp(possible_loc.size());
	
	for (int i = 0; i < m; i++){
		tmp[i] = 1; // 고른 거
	}
	
	//tmp[2] = 1; tmp[3] = 1; tmp[7] = 1; tmp[8] = 1;
	int min_t = 3000; // 전체 케이스에서 전염시키는데 걸리는 최소 시간

	do{
		queue<pair<int, int>> q;
		//int cnt = 0; // 이 케이스에서 모두 전염시키는 데 걸리는 시간
		// 초기 활성화 함수 
		for (int i = 0; i < possible_loc.size(); i++){
			if (tmp[i] == 1) {
				q.push(possible_loc[i]);
				int t_x = possible_loc[i].first;
				int t_y = possible_loc[i].second;
				dist[t_x][t_y] = 0;
				check[t_x][t_y] = true;
			}
			else if (tmp[i] == 0){ // 비활성 바이러스
				int t_x = possible_loc[i].first;
				int t_y = possible_loc[i].second;
				dist[t_x][t_y] = -1;
			}
		}
		int dist_max = 0;
		while (!q.empty()){
			// 모두 check되었는 지 확인
			// 아니라면 cnt 추가
			bool keep = false;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					if (check[i][j] == false){
						keep = true;
						break;
					}
				}
			}
			if (keep == false) break;// 모두 check된 경우 종료
			//cnt++;

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if ((check[nx][ny] == true && dist[nx][ny] == -1) || (check[nx][ny] == false)){
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					dist_max = (dist[nx][ny] > dist_max) ? dist[nx][ny] : dist_max;
					q.push(make_pair(nx, ny));
				}
			}
		}
		// 모두 check 인지 확인
		bool keep2 = true;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (check[i][j] == false){
					keep2 = false;
				}
			}
		}
		if (keep2 == true) {
			if (min_t > dist_max){
				min_t = dist_max; // 더 짧은 시간 걸린 경우 min_t 업데이트
				temp = tmp;
			}
		}
		// check, dist 초기화
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (map[i][j] == 2 || map[i][j] == 1) check[i][j] = true;
				else check[i][j] = false;
				dist[i][j] = 0;
			}
		}

	} while (prev_permutation(tmp.begin(), tmp.end()));

	if (min_t != 3000) cout << min_t << endl;
	else cout << -1 << endl;

	return 0;
}
