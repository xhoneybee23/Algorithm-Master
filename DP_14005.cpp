#include <iostream>
using namespace std;

// LIS (Longest Increasing Subsequence) Problem Extended
// LIS 의 길이와 해당 부분 수열도 출력
// 부분 수열 출력 위해 이전 노드 인덱스를 저장하는 p 배열을 선언하고 go 함수로 인덱스 트랙킹하며 부분 수열 찾음
// 부분 수열은 f에 저장해둠

int a[1001];
int t[1001];
int p[1001];
int f[1001];

void go(int idx, int size){
	f[size] = a[idx];
	if (size == 1) return;
	go(p[idx], size - 1);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		scanf_s("%d", &a[i]);
	}

	for (int j = 1; j <= n; j++){
		t[j] = 1;
		p[j] = j;
		for (int k = j - 1; k >= 1; k--){
			if (a[k] < a[j] && t[j] < t[k] + 1) {
				t[j] = t[k] + 1;
				p[j] = k;
			}
		}
	}

	int temp = t[1];
	int idx = 1;
	for (int i = 2; i <= n; i++){
		if (t[i] > temp){
			temp = t[i];
			idx = i;
		}
	}
	cout << temp << endl;

	go(idx, t[idx]);

	for (int j = 1; j <= t[idx]; j++){
		if (j == t[idx]) printf("%d\n", f[j]);
		else printf("%d ", f[j]);
	}

	return 0;
}
