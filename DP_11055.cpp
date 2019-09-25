#include <iostream>
using namespace std;

// LIS(Longest Increasing Subsequence) Problem Extended
// 합이 가장 큰 증가 수열

int a[1001];
int s[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		scanf_s("%d", &a[i]);
	}

	for (int j = 1; j <= n; j++){
		s[j] = a[j];
		for (int k = j - 1; k >= 1; k--){
			if ((a[j] > a[k]) && (a[j] + s[k] > s[j])){
				s[j] = a[j] + s[k];
			}
		}
	}

	int temp = s[1];
	for (int i = 1; i <= n; i++){
		temp = (s[i] > temp) ? s[i] : temp;
	}
	cout << temp << endl;

	return 0;
}
