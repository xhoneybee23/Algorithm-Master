#include <iostream>
using namespace std;

// bottom-up
// LIS(Longest Increasing Subsequence) Problem 

int d[1001];
int b[1001]; // before the value ���� ����
int a[1001]; // after the value ���� ����

int main(){
	int n;
	cin >> n;

	// �Է°�
	for (int i = 1; i <= n; i++){
		scanf_s("%d", &d[i]);
	}

	b[0] = 0;

	// ���� ���� ã�� 
	// b ä���
	for (int j = 1; j <= n; j++){
		b[j] = 1;
		for (int k = j - 1; k >= 1; k--){
			if ((d[k] < d[j]) && (b[j] < b[k] + 1)) b[j] = b[k] + 1;
		}
	}

	// ���� ���� ã��
	// a ä���
	// ������ value ���� �� �ڸ� ���� �����ϴ� �� ã���� ���� value�� �Ѿ
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