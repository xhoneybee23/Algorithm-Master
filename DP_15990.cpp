#include <iostream>
using namespace std;

// Unsolved
// input이 10,000 을 넘어가면 안돌아감

long long d[200001][4];

long long go(int n, int m){
	if (d[n][m] >= 0) return d[n][m];

	//d[n][m] = 0;

	long long temp;

	if (m == 1) temp = (go(n - 1, 2) + go(n - 1, 3)) % 1000000009;
	if (m == 2) temp = (go(n - 2, 1) + go(n - 2, 3))% 1000000009;
	if (m == 3) temp = (go(n - 3, 1) + go(n - 3, 2)) % 1000000009;

	d[n][m] = temp;

	return d[n][m];
}

int main() {
	int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	d[1][1] = 1; d[1][2] = 0; d[1][3] = 0;
	d[2][2] = 1; d[2][1] = 0; d[2][3] = 0;
	d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;

	while (n--){
		long long input;
		cin >> input;
		long long result = 0;
		for (int i = 1; i <= 3; i++){
			result += (go(input, i));
		}

		result %= 1000000009;

		cout << result << endl;
	}

	return 0;
}
