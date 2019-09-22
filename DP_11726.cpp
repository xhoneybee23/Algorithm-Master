#include <iostream>
using namespace std;

// Top-down
// 연산 결과가 너무 클땐, 특정 소수로 나눴을 때의 나머지를 반환하라고 하는 경우가 있다.
// 이럴 땐 그 결과 그대로 저장해두는 것 보다는 그 소수로 나눈 나머지들을 저장해두는 게 나중에 int 범위 넘어가도 안전함.
// (A+B)%C = ((A%C)+(B%C))%C

int d[1001];

int go(int n){
	if (d[n] > 0) return d[n];
	long long temp = go(n - 1) + go(n - 2); // 나머지들을 더하고
	d[n] = temp%10007; // 또 특정 소수로 나눈 나머지를 저장

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
