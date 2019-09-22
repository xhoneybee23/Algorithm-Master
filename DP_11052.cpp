#include <iostream>
using namespace std;

// 시간복잡도 O(N^2)

int price[1001];
int d[1001];

int go(int n){
	if (d[n] > 0) return d[n];
	
	d[n] = price[n];
	
	for (int j = 0; j < n; j++){
		d[n] = (d[n] < go(n - j) + go(j)) ? go(n - j) + go(j) : d[n];
	}
	
	return d[n];
}

int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++){
		// scanf("%d ", ~) 로 선언하면 숫자를 하나 더 받음
		scanf("%d", &price[i]);
	}
	d[0] = 0;
	d[1] = price[1];

	cout << go(n) << endl;
	
	return 0;
}
