#include <iostream>
#include <deque>
using namespace std;

int main(){
	int s, d;
	bool check[100001] = { false };
	int dist[100001];

	cin >> s >> d;

	deque<int> q;

	q.push_back(s);
	check[s] = true;
	dist[s] = 0;

	while (!q.empty()){
		int x = q.front();
		q.pop_front();

		if (x == d) {
			cout << dist[x] << endl;
			break;
		}
		if (check[2 * x] == false && 2 * x <= 2 * d && 2 * x <= 100000){
			q.push_front(2 * x);
			check[2 * x] = true;
			dist[2 * x] = dist[x];
		}

		if (check[x + 1] == false && x + 1 <= 100000){
			q.push_back(x + 1);
			check[x + 1] = true;
			dist[x + 1] = dist[x] + 1;
		}

		if (check[x - 1] == false && x - 1 >= 0){
			q.push_back(x - 1);
			check[x - 1] = true;
			dist[x - 1] = dist[x] + 1;
		}

	}
	//cout << dist[d] << endl;
	return 0;
}