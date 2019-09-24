#include <iostream>
using namespace std;

int point[3][100001];
int d[100001][4];

int max(int x, int y, int z){
	int temp = (x > y) ? x : y;
	temp = (z > temp) ? z : temp;

	return temp;
}

int main() {
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= n; j++){
				scanf_s("%d", &point[i][j]);
			}
		}

		d[0][1] = 0; d[0][2] = 0; d[0][3] = 0;
		
		for (int k = 1; k <= n; k++){
			d[k][1] = max(d[k - 1][1], d[k - 1][2], d[k - 1][3]); // 아무것도 선택 안함
			d[k][2] = max(d[k - 1][1], d[k - 1][3], -1)+point[1][k]; // 위쪽 스티커 선택
			d[k][3] = max(d[k - 1][1], d[k - 1][2], -1)+point[2][k]; // 아래쪽 스티커 선택

		}

		cout << max(d[n][1], d[n][2], d[n][3]) << endl;

		memset(point, 0, sizeof(point));
		memset(d, 0, sizeof(d));

	}

	return 0;
}