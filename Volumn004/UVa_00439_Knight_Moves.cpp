//Fri Apr  8 18:53:31 CDT 2011
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Square {
public:
	int x;
	int y;
	int cost;
	bool visited;

	Square(int i, int j, int c, bool v) {
		this->x = i;
		this->y = j;
		this->cost = c;
		this->visited = v;
	}
};

int xx[] = { -2, -1, +1, +2, +2, +1, -1, -2 };
int yy[] = { -1, -2, -2, -1, +1, +2, +2, +1 };

vector<vector<Square> > chess;
queue<Square> q;

void init() {
	chess.clear();
	while (q.empty() == false)
		q.pop();
	for (int i = 0; i < 8; i++) {
		vector<Square> tmp;
		for (int j = 0; j < 8; j++) {
			tmp.push_back(Square(i, j, 0, false));
		}
		chess.push_back(tmp);
	}
	//	for (int i = 0; i < 8; i++)
	//		for (int j = 0; j < 8; j++)
	//			cout << "Chess at " << chess[i][j].x << chess[i][j].y << ": "
	//					<< chess[i][j].cost << ", visited: "
	//					<< (chess[i][j].visited == true ? 1 : 0) << endl;
}

bool checkBound(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	return false;
}

int bfs(string a, string b) {
	int x = a[0] - 'a';
	int y = a[1] - '1';
	chess[x][y].cost = 0;
	q.push(chess[a[0] - 'a'][a[1] - '1']);
	while (q.empty() == false) {
		Square tmp = q.front();
//		cout << "here?" << endl;
		q.pop();
		x = tmp.x;
		y = tmp.y;
//		cout << x << ", " << y << endl;
		if (chess[x][y].visited == false) {
			chess[x][y].visited = true;
			if (x == b[0] - 'a' && y == b[1] - '1')
				return chess[x][y].cost;
			for (int i = 0; i < 8; i++) {
				int x1 = x + xx[i];
				int y1 = y + yy[i];
				if (checkBound(x1, y1)) {
					chess[x1][y1].cost = 1 + chess[x][y].cost;
					q.push(chess[x1][y1]);
				}
			}
		}
	}
	return 0;
}

int main(int argc, const char* argv[]) {
	//freopen("input.in", "r", stdin);
	string a, b;
	while (cin >> a >> b) {
		init();
		cout << "To get from " << a << " to " << b << " takes " << bfs(a, b)
				<< " knight moves." << endl;
	}
	//fclose(stdin);
	return 0;
}
