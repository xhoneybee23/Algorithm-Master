#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0}; 

int main() {
	int n, m;
	cin >> n >> m;
	//memset(map, -1, sizeof(map));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf_s("%1d", &map[i][j]);
		}
	}

	queue<pair<int, int>> q;

	// ù ĭ �湮
	check[0][0] = true;
	q.push(make_pair(0, 0));
	dist[0][0] = 1;

	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && ny > 0 && nx < n && ny < m && check[nx][ny] == false && map[nx][ny] == 1){
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
				check[nx][ny] = true;
			}
		}
	}

	cout << dist[n-1][m-1] << endl;
}