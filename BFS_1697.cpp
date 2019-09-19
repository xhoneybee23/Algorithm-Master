#include <iostream>
#include <queue>
using namespace std;


// 유의사항 : 현재의 값에서 연산을 해보고 원하는 destination값이면 dist[현재]+1 로 출력하면 최저값이 안나옴
// 큐에 넣으면서 destination 값과 비교하면 안됨
// 그 이유는 현재의 값과 동일한 depth에 있는 후보 중에 원하는 destination 값이 있을 수 있음
// 그럼 답은 dist[현재]가 되는 것임

int main() {
	int s, d;
	int dist[100001] = { 0 };
	bool check[100001] = { false };

	cin >> s >> d;

	queue <int> q;
	q.push(s);
	dist[s] = 0;
	check[s] = true;

	while (!q.empty()){
		int x = q.front();

		q.pop();

		int s_1 = x + 1;
		if (s_1 >= 0 && s_1 <= 100000 && check[s_1] == false){
			q.push(s_1);
			dist[s_1] = dist[x] + 1;
			check[s_1] = true;
			
		}
		int s_2 = x - 1;
		if (s_2 >= 0 && s_2 <= 100000 && check[s_2] == false){
			q.push(s_2);
			dist[s_2] = dist[x] + 1;
			check[s_2] = true;
		}
		int s_3 = 2 * x;
		if (s_3 >= 0 && s_3 <= 100000 && check[s_3] == false){
			q.push(s_3);
			dist[s_3] = dist[x] + 1;
			check[s_3] = true;
		}

	}

	cout << dist[d] << endl;
	return 0;
}
