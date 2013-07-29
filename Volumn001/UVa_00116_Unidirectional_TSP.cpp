//Sun Apr 10 03:06:20 CDT 2011
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
#define INT_MAX 2147483647
#define INT_MIN -2147483647

using namespace std;

class Point {
public:
	int x;
	int y;
};

void init(int m, int n, vector<vector<int> > &matrix,
		vector<vector<Point> > &parent) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			parent[i][j].x = i;
			parent[i][j].y = j;
		}
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++)
	//			cout << matrix[i][j] << " ";
	//		cout << endl;
	//	}
}

void reverseVector(vector<vector<int> > &v) {
	for (int i = 0; i < (int) v.size(); i++)
		reverse(v[i].begin(), v[i].end());
}

bool cmp(const vector<int> A, const vector<int> B) {
	for (int i = 0; i < (int) A.size(); i++) {
		if (A[i] > B[i])
			return false;
		if (A[i] < B[i])
			return true;
	}
	return true;
}

pair<int, vector<int> > Path(int m, int n, vector<vector<int> > &matrix,
		vector<vector<Point> > &parent) {
	vector<vector<int> > consume(m, vector<int> (n, INT_MAX));
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++)
	//			cout << consume[i][j] << " ";
	//		cout << endl;
	//	}
	for (int i = 0; i < m; i++)
		consume[i][n - 1] = matrix[i][n - 1];
	//consume[0][0] = matrix[0][0];

	for (int j = n - 2; j >= 0; j--) {
		for (int i = 0; i < m; i++) {
			vector<int> pos;
			pos.push_back(i);
			pos.push_back((i + 1) % m);
			pos.push_back((i + m - 1) % m);
			sort(pos.begin(), pos.end());
			for (int k = 0; k < 3; k++) {
				if (consume[pos[k]][j + 1] != INT_MAX && consume[i][j]
						> matrix[i][j] + consume[pos[k]][j + 1]) {
					consume[i][j] = matrix[i][j] + consume[pos[k]][j + 1];
					parent[i][j].x = pos[k];
					parent[i][j].y = j + 1;
				}
			}
		}
	}
	//	for (int j = 0; j < n; j++)
	//		for (int i = 0; i < m; i++) {
	//			cout << consume[i][j] << ": " << parent[i][j].x << ", "
	//					<< parent[i][j].y << endl;
	//		}
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++)
	//			cout << consume[i][j] << " ";
	//		cout << endl;
	//	}
	int mmin = INT_MAX;
	for (int i = 0; i < m; i++) {
		if (mmin > consume[i][0]) {
			mmin = consume[i][0];
		}
	}
	vector<vector<int> > ret;
	for (int i = 0; i < m; i++) {
		if (consume[i][0] == mmin)
			ret.push_back(vector<int> (1, i));
	}
	for (int j = 0; j < (int) ret.size(); j++) {
		int xx = ret[j][0];
		int yy = 0;
		ret[j][0]++;
		for (int i = 0; i < n - 1; i++) {
			xx = parent[xx][yy].x;
			yy = parent[xx][yy].y;
			ret[j].push_back(xx + 1);
		}
	}
//	reverseVector(ret);
//	for (int i = 0; i < ret.size(); i++) {
//		for (int j = 0; j < ret[i].size(); j++)
//			cout << ret[i][j] << " ";
//		cout << endl;
//	}
	sort(ret.begin(), ret.end(), cmp);
//	for (int i = 0; i < ret.size(); i++) {
//		for (int j = 0; j < ret[i].size(); j++)
//			cout << ret[i][j] << " ";
//		cout << endl;
//	}
	return make_pair(mmin, ret[0]);
}

void print(pair<int, vector<int> > v) {
	cout << v.second[0];
	for (int i = 1; i < (int) v.second.size(); i++)
		cout << " " << v.second[i];
	cout << endl;
	cout << v.first << endl;
}

int main(int argc, char* argv[]) {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int> > matrix(m, vector<int> (n, 0));
		vector<vector<Point> > parent(m, vector<Point> (n));
		init(m, n, matrix, parent);
		print(Path(m, n, matrix, parent));
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

