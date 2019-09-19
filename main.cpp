#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, m;
	int map[100][100];
	bool check[100][100] = { false };
	int dist[100][100];
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	cin >> n >> m;  //n이 열, m이 행
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	deque<pair<int, int>> q;

	q.push_back(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 0;

	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;

		q.pop_front();

		for (int k = 0; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (check[nx][ny] == false && nx >= 0 && nx<m && ny >= 0 && ny<n){
				//빈 칸인 경우
				if (map[nx][ny] == 0){
					q.push_front(make_pair(nx, ny));
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y];
				}
				//벽인 경우
				else{
					q.push_back(make_pair(nx, ny));
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}

	cout << dist[m - 1][n - 1] << endl;

	return 0;
}