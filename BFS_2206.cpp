#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;


// unsolved 

int m, n;
int map[1001][1001];
bool check[1001][1001][2];
int dist[1001][1001][2];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main() {
	memset(check, false, sizeof(check));
	memset(dist, -1, sizeof(dist));

	cin >> m >> n;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf_s("%1d", &map[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;

	q.push(make_tuple(0, 0, 0));
	check[0][0][0] = true;
	dist[0][0][0] = 1;

	while (!q.empty()){
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		if (x == m - 1 && y == n - 1){
			int result = (dist[m - 1][n - 1][0] >= dist[m - 1][n - 1][1]) ? dist[m - 1][n - 1][0] : dist[m - 1][n - 1][1];

			cout << result << endl;
			return 0;
		}

		for (int k = 0; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n){
				if (check[nx][ny][0] == false && check[nx][ny][1] == false){ //z==0 인 경우와 1인 경우 모두 비교해봐야하나?
					if (z == 0 && map[nx][ny] == 0) {// 벽을 부순적이 없고, 빈 방일 때
						check[nx][ny][z] = true;
						q.push(make_tuple(nx, ny, z));
						dist[nx][ny][z] = dist[x][y][z] + 1;
					}
					else if (z == 0 && map[nx][ny] == 1) { // 벽을 부순 적이 없고, 벽일 때
						check[nx][ny][z + 1] = true;
						q.push(make_tuple(nx, ny, z + 1));
						dist[nx][ny][z + 1] = dist[x][y][z] + 1;
					}
					else if (z == 1 && map[nx][ny] == 0) { // 벽을 부순 적이 있고, 빈 방일 때
						check[nx][ny][z] = true;
						q.push(make_tuple(nx, ny, z));
						dist[nx][ny][z] = dist[x][y][z] + 1;
					}
					else continue; // 벽을 부순 적이 있고, 벽일 때는 넘어간다
				}
			}
		}
	}

	//int result = (dist[m - 1][n - 1][0] >= dist[m - 1][n - 1][1]) ? dist[m - 1][n - 1][0] : dist[m - 1][n - 1][1];
	int a = -1;
	cout << a << endl;
	return 0;
}
