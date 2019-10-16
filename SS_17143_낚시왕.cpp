#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, m, sum = 0;

int dx[] = { 0, -1, 1, 0, 0 }; // 0: 그대로, 1:위, 2:아래, 3:오른쪽, 4:왼쪽
int dy[] = { 0, 0, 0, 1, -1 };

int map[101][101];
int _x, _y, _speed, _dir;

typedef struct Shark {
	int x;
	int y;
	int speed;
	int dir;
	int size;
} Shark;

void go(int x, int y, int speed, int dir){
	if (speed == 0) { 
		_x = x; 
		_y = y;
		_dir = dir;
		return;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 행 방향으로 움직인 경우 (위 아래)
	if (nx != x){
		if (nx > r){
			nx = r - 1;
			dir = 1;
		}
		else if (nx < 1){
			nx = 2;
			dir = 2;
		}
	}

	// 열 방향으로 움직인 경우 (좌 우)
	else if (ny != y){
		if (ny > c){
			ny = c - 1;
			dir = 4;
		}
		else if (ny < 1){
			ny = 2;
			dir = 3;
		}
	}

	go(nx, ny, speed - 1, dir);
	return;
}

int main(){
	cin >> r >> c >> m;
	vector<Shark> shark_list;

	for (int i = 1; i <= m; i++){
		Shark temp;
		cin >> temp.x >> temp.y >> temp.speed >> temp.dir >> temp.size;
		shark_list.push_back(temp);
	}

	for (int j = 1; j <= c; j++){
		// j 열에서 땅과 가장 가까운 상어 찾기
		int shortest = 200;
		int shortest_idx;
		for (int k = 0; k < shark_list.size(); k++){
			if (shark_list[k].y == j){
				if (shark_list[k].x < shortest) {
					shortest = shark_list[k].x;
					shortest_idx = k;
				}
			}
		}
		// 가까운 상어가 있다면 잡기
		if (shortest != 200) {
			sum += shark_list[shortest_idx].size;
			shark_list.erase(shark_list.begin() + shortest_idx);
		}

		// 상어 이동
		for (int i = 0; i < shark_list.size(); i++){
			Shark temp = shark_list[i];
			go(temp.x, temp.y, temp.speed, temp.dir);
			shark_list[i].x = _x;
			shark_list[i].y = _y;
			shark_list[i].dir = _dir;
		}

		// 이동 후 같은 위치 상어 잡아먹기 // 두 마리 이상일 수 도 있다 // 잡아먹히고 잡아먹히고?
		vector<int> obj_to_be_erased;

		for (int i = 0; i < shark_list.size(); i++){
			for (int a = i + 1; a < shark_list.size(); a++){
				if (shark_list[i].x == shark_list[a].x && shark_list[i].y == shark_list[a].y) {
					if (shark_list[i].size >= shark_list[a].size) obj_to_be_erased.push_back(a);
					else obj_to_be_erased.push_back(i);
				}
			}
		}
		//sort(obj_to_be_erased.begin(), obj_to_be_erased.end());
		obj_to_be_erased.erase(unique(obj_to_be_erased.begin(), obj_to_be_erased.end()), obj_to_be_erased.end());

		// 잡아먹기
		if (obj_to_be_erased.size() > 0){
			/*
			if (obj_to_be_erased.size() == 1) {
				shark_list.erase(shark_list.begin() + obj_to_be_erased[0]);
				break;
			}*/
			vector<Shark> temp;
			bool keep = true;
			for (int c = 0; c < shark_list.size(); c++){
				for (int d = 0; d < obj_to_be_erased.size(); d++){
					if (c == obj_to_be_erased[d]) keep = false;
				}
				if (keep == true) temp.push_back(shark_list[c]);
				keep = true;
			}
			shark_list = temp;
		}

	
	}

	cout << sum << endl;

	return 0;
}
