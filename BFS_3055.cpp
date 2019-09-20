#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// unsolved
// 코드가 지저분해서 정리해야함

char map[50][50];
bool check[50][50];
bool check2[50][50];
int dist[50][50];
int dist2[50][50];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	int m, n;
	//cin >> m >> n;
	scanf("%d %d\n", &m, &n);

	memset(check, false, sizeof(check));
	memset(dist2, -1, sizeof(dist2));
	memset(check2, false, sizeof(check2));

	int wx, wy, sx, sy, dx2, dy2;
	char junk;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%c", &map[i][j]);
			if (map[i][j] == '*') {
				wx = i;
				wy = j;
			}
			if (map[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if (map[i][j] == 'D'){
				dx2 = i;
				dy2 = j;
			}
		}
		if (i != m - 1) scanf("\n", &junk);
	}

	// 물이 채워지는 BFS 만들기
	queue <pair<int, int>> wq;

	wq.push(make_pair(wx, wy));
	check[wx][wy] = true;
	dist[wx][wy] = 0;

	while (!wq.empty()){
		int _x = wq.front().first;
		int _y = wq.front().second;

		wq.pop();

		for (int k = 0; k < 4; k++){
			int nx = _x + dx[k];
			int ny = _y + dy[k];

			if (check[nx][ny] == false){
				if (nx >= 0 && nx < m && ny >= 0 && ny < n){
					if (map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
					else{
						wq.push(make_pair(nx, ny));
						dist[nx][ny] = dist[_x][_y] + 1;
						check[nx][ny] = true;
					}
				}
			}
		}
	}

	//Source에서 Destination까지 물과 돌을 피해가자
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check2[sx][sy] = true;
	dist2[sx][sy] = 0;

	while (!q.empty()){
		int __x = q.front().first;
		int __y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++){
			int nnx = __x + dx[k];
			int nny = __y + dy[k];

			if (check2[nnx][nny] == false && map[nnx][nny] != 'X'){
				if (nnx >= 0 && nnx < m && nny >= 0 && nny < n){
					if ((nnx == dx2 && nny == dy2) || dist[nnx][nny] > dist2[__x][__y] + 1){
						q.push(make_pair(nnx, nny));
						check2[nnx][nny] = true;
						dist2[nnx][nny] = dist2[__x][__y] + 1;
					}
					else continue;
				}
			}
		}
	}

	if (dist2[dx2][dy2] == -1) {
		cout << "KAKTUS" << endl;
		return 0;
	}
	else {
		cout << dist2[dx2][dy2] << endl;
		return 0;
	}
}
