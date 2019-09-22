#include <iostream>
using namespace std;

// Top-down

int d[11];

int go(int n){
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + go(n - 2) + go(n - 3);
	return d[n];
}

int main() {
	// 문제 상 d[0]가 아무 의미 또는 값이 없을 수 있는 데, 
	//지금 초기화하는 값보다 큰 값 중 가장 작은 값을 연산할 때 값이랑 맞도록 d[0]를 설정해주는 것이 편함. 여기선 d[3]
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
