#include <iostream>
#include <math.h>
using namespace std;

// Top-down
// 제곱수의 합

int d[100001];

int go(int n){
	if (d[n] > 0) return d[n];
	if (n == 1) return 1;
	if (n == 0) return 0;

	int temp = 100001;

	int i=(int)sqrt(n);

	for ( ; i>=1; i--){
		d[n - (i*i)] = go(n - (i*i));
		temp = (d[n - (i*i)] < temp) ? d[n - (i*i)] : temp;
	}

	d[n] = temp + 1;
	return d[n];
}

int main() {
	int n;
	cin >> n;

	cout << go(n) << endl;

	return 0;
}
