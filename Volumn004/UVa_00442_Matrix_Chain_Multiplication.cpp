//Wed Apr 13 13:38:48 CDT 2011
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

class Matrix {
public:
	int row;
	int col;
	Matrix() {
		this->row = -1;
		this->col = -1;
	}
	Matrix(int r, int c) {
		this->row = r;
		this->col = c;
	}
};
vector<Matrix> mat;

void init(int N) {
	char c;
	int a, b;
	mat.clear();
	mat.resize(26);
	for (int i = 0; i < N; i++) {
		cin >> c >> a >> b;
		mat[c - 'A'] = Matrix(a, b);
	}
	//	for (int i = 0; i < 26; i++)
	//		cout << char('A' + i) << mat[i].row << ", " << mat[i].col << endl;
}

int process(string s) {
	stack<Matrix> expression;
//	cout << s << endl;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			continue;
		else if (s[i] == ')') {
			Matrix a = expression.top();
			expression.pop();
			Matrix b = expression.top();
			expression.pop();
			if (a.row != b.col)
				return -1;
			sum += b.row * b.col * a.col;
			expression.push(Matrix(b.row, a.col));
		} else
			expression.push(mat[s[i] - 'A']);
	}
	return sum;
}

void solve() {
	string s;
	while (cin >> s) {
		int ret = process(s);
		if (ret != -1)
			cout << ret << endl;
		else
			cout << "error" << endl;
	}
}

int main(int argc, const char* argv[]) {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	init(N);
	solve();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

