#include <iostream>
using namespace std;

int g[10001];
int t[10001][3];

int max(int x, int y, int z){
	int temp = (x > y) ? x : y;
	temp = (z > temp) ? z : temp;

	return temp;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> g[i];
	}

	g[0] = 0;
	t[0][0] = 0; t[0][1] = 0; t[0][2] = 0;

	for (int j = 1; j <= n; j++){
		t[j][0] = max(t[j-1][0], t[j-1][1], t[j-1][2]);
		t[j][1] = t[j - 1][0] + g[j];
		t[j][2] = t[j - 1][1] + g[j];
	}

	cout << max(t[n][0], t[n][1], t[n][2]) << endl;

	return 0;
}