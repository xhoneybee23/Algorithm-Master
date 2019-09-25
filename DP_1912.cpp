#include <iostream>
using namespace std;

// 연속합 문제 - 중요함
// n번째 자리에서 이전까지의 연속합을 n번째 value와 더하는게 이득인가 손실인가를 따지면 됨

int a[100001];
int d[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	d[0] = 0;

	for (int j = 1; j <= n; j++){
		d[j] = a[j];
		if (d[j - 1] + a[j] > a[j]) d[j] = d[j - 1] + a[j];
	}

	int temp = d[1];

	for (int k = 1; k <= n; k++){
		temp = (d[k] > temp) ? d[k] : temp;
	}

	cout << temp << endl;

	return 0;

}
