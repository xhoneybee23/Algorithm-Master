#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//dist를 2차원 배열이 아니라 1차원 배열로 선언해도 되지 않을까 생각이 들 수 있다.
//하지만 조금만 경우의 수를 일일히 따라가다보면 클립보드의 상태도 dist값에 영향을 미치는 것을 알 수 있다.

int dist[1001][1001];
bool check[1001][1001] = { false };

int main() {
	memset(dist, -1, sizeof(dist));
	int s;

	cin >> s;

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	check[1][0] = true;
	dist[1][0] = 0;

	while (!q.empty()){
		int nm = q.front().first;
		int nc = q.front().second;
		q.pop();

		if (nm == s){
			cout << dist[nm][nc] << endl;
			break;
		}

		//화면의 이모티콘을 클립보드에 복사
		if (check[nm][nm] == false){
			q.push(make_pair(nm, nm));
			check[nm][nm] = true;
			dist[nm][nm] = dist[nm][nc] + 1;
		}
		//화면에 클립보드의 이모티콘 붙여넣기
		if (check[nm + nc][nc] == false && nm + nc <= 1000 && nc != 0){
			q.push(make_pair(nm + nc, nc));
			check[nm + nc][nc] = true;
			dist[nm + nc][nc] = dist[nm][nc] + 1;
		}
		//화면의 이모티콘 1개 삭제
		if (check[nm - 1][nc] == false && nm - 1 >= 0){
			q.push(make_pair(nm - 1, nc));
			check[nm - 1][nc] = true;
			dist[nm - 1][nc] = dist[nm][nc] + 1;
		}
	}

	return 0;

}
