#include <iostream>
using namespace std;

int d[1001];

int go(int n){
	if (d[n] > 0) return d[n];
	long long temp = go(n - 1) + go(n - 2);
	d[n] = temp%10007;

	return d[n];
}

int main() {

	d[0] = 1;
	d[1] = 1;

	int n;
	cin >> n;
	cout << go(n) << endl;
	
	return 0;
}