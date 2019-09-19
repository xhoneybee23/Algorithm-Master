#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dist[1001][1001];
bool check[1001][1001] = { false };

int main() {
	memset(dist, -1, sizeof(dist));
	int s;

	cin >> s;

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	check[1][0] = true;
	dist[1][0] = 0;

	while (!q.empty()){
		int nm = q.front().first;
		int nc = q.front().second;
		q.pop();


		if (nm == s){
			cout << dist[nm][nc] << endl;
			break;
		}

		//ȭ���� �̸�Ƽ���� Ŭ�����忡 ����
		if (check[nm][nm] == false){
			q.push(make_pair(nm, nm));
			check[nm][nm] = true;
			dist[nm][nm] = dist[nm][nc] + 1;
		}
		//ȭ�鿡 Ŭ�������� �̸�Ƽ�� �ٿ��ֱ�
		if (check[nm + nc][nc] == false && nm + nc <= 1000 && nc != 0){
			q.push(make_pair(nm + nc, nc));
			check[nm + nc][nc] = true;
			dist[nm + nc][nc] = dist[nm][nc] + 1;
		}
		//ȭ���� �̸�Ƽ�� 1�� ����
		if (check[nm - 1][nc] == false && nm - 1 >= 0){
			q.push(make_pair(nm - 1, nc));
			check[nm - 1][nc] = true;
			dist[nm - 1][nc] = dist[nm][nc] + 1;
		}
	}

	return 0;

}