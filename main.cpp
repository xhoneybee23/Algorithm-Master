#include <iostream>
using namespace std;

long long mod = 1000000000LL;
int MAX = 100;
long long d[101][10];

int main() {
	int n;
	cin >> n;

	//d[1][0] = 0;

	for (int i = 1; i <= 9; i++) d[1][i] = 1;

	for (int j = 2; j <= MAX; j++){
		for (int k = 0; k <= 9; k++){
			if (k == 0) d[j][k] = d[j - 1][k+1];
			if (k == 9) d[j][k] = d[j - 1][k-1];
			else d[j][k] = d[j - 1][k - 1] + d[j - 1][k + 1];

			d[j][k] %= mod;
		}
	}

	long long result = 0;

	for (int i = 0; i <= 9; i++){
		result += d[n][i];
	}

	result %= mod;

	cout << result << endl;

	return 0;
}