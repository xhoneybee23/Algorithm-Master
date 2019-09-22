#include <iostream>
using namespace std;

int d[11];

int go(int n){
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + go(n - 2) + go(n - 3);
	return d[n];
}

int main() {
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	int n;
	cin >> n;
	while (n--){
		int m;
		cin >> m;
		cout << go(m) << endl;
	}
}