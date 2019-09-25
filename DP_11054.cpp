#include <iostream>
using namespace std;

// bottom-up
// LIS(Longest Increasing Subsequence) Problem Extended
// 가장 긴 바이토닉 부분 수열

int d[1001];
int b[1001]; // before the value 증가 수열
int a[1001]; // after the value 감소 수열

int main(){
	int n;
	cin >> n;

	// 입력값
	for (int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
	}

	b[0] = 0; a[0] = 0;

	// 증가 수열 찾기 
	// b 채우기
	for (int j = 1; j <= n; j++){
		b[j] = 1;
		for (int k = j - 1; k >= 1; k--){
			if ((d[k] < d[j]) && (b[j] < b[k] + 1)) b[j] = b[k] + 1;
		}
	}

	// 감소 수열 찾기
	// a 채우기
	// 마지막 value 부터 그 뒤를 보며 감소하는 값 찾고나서 앞의 value로 넘어감
	for (int j = n; j >= 1; j--){
		a[j] = 1;
		for (int k = j + 1; k <= n; k++){
			if ((d[j]>d[k]) && (a[j] < a[k] + 1)) a[j] = a[k] + 1;
		}
	}

	int max = a[1]+b[1]-1;

	for (int i = 2; i <= n; i++){
		max = (a[i]+b[i]-1 > max) ? a[i]+b[i]-1 : max;
	}

	cout << max << endl;

	return 0;

}
