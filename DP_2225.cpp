#include <iostream>
using namespace std;

// 합분해

long long d[201][201];
const long long mod = 1000000000LL;

int go(int k, int n){
	if (k == 1) return 1;
	if (k == 0) return 0;
	if (d[k][n] > 0) return d[k][n];

	for (int x = 0; x <= n; x++){
		d[k][n] += go(k - 1, n - x);
	}

	d[k][n] %= mod;

	return d[k][n];
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << go(k, n) << endl;
	return 0;
}
