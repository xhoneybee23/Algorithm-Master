#include <iostream>
#include <cstring>
using namespace std;

// Top-down

int d[1000000];

int go(int n){
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	
	d[n] = go(n - 1) + 1;

	if (n % 2 == 0){
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0){
		int temp2 = go(n / 3) + 1;
		if (d[n] > temp2) d[n] = temp2;
	}

	return d[n];
}

int main() {

	memset(d, 0, sizeof(d));

	int n;
	cin >> n;
	cout << go(n) << endl;

	return 0;
}
