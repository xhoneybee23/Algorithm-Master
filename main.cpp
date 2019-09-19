#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
bool check[1000][1000];
int dist[1000][1000];

int main() {
	int m, n;
	
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	cin >> n >> m;
	bool possible = false; // for문 다 돌고 false면 토마토는 다 익을 수 없다
	bool every_tomato = true; // for문 다 돌고 true면 모두 다 익은 토마토
	
	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				possible = true;
				q.push(make_pair(i, j));
				check[i][j] = true;
				dist[i][j] = 1;
			}
				if (tomato[i][j] == 0) every_tomato = false;
			}
		}
		if (!possible) cout << "-1";
		else if (every_tomato) cout << "0";
		else if (possible || !every_tomato){
			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++){
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < m && ny >= 0 && ny < n){
						if (tomato[nx][ny] == 0 && check[nx][ny] == false){
							q.push(make_pair(nx, ny));
							check[nx][ny] = true;
							dist[nx][ny] = dist[x][y] + 1;
						}
					}
				}
			}
			int max = 0;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					if (dist[i][j] == 0 && tomato[i][j] != -1) {
						cout << "-1";
						return 0;
					}
					else if (dist[i][j] > max) max = dist[i][j];
				}
			}
			cout << max-1;
		}
		
	
	return 0;
}