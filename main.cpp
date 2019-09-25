#include <iostream>
using namespace std;

int a[100001];
int d[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		scanf_s("%d", &a[i]);
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