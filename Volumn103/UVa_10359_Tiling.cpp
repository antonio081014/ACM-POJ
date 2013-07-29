//Thu Jul  8 10:33:36 CDT 2010
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
#define MMAX 251
using namespace std;

vector<int> Tiling(vector<vector<int> > &v, int N)
{
	if (N == 0)
	{
		v[0][0] = 1;
		return v[0];
	}
	if (N == 1)
	{
		v[1][0] = 1;
		return v[1];
	}
	if (N == 2)
	{
		v[2][0] = 3;
		return v[2];
	}
	for (int i = 0; i < MMAX; i++)
		if (v[N][i] != 0)
			return v[N];
	v[N - 1] = Tiling(v, N - 1);
	v[N - 2] = Tiling(v, N - 2);
	int flag = 0;
	int i;
	for (i = 0; i < MMAX; i++)
	{
		v[N][i] = v[N - 1][i] + v[N - 2][i] * 2 + flag;
		if (v[N][i] >= 10)
		{
			flag = v[N][i] / 10;
			v[N][i] %= 10;
		}
		else
			flag = 0;
	}
	return v[N];
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	vector<vector<int> > v(MMAX, vector<int> (MMAX));
	for (int i = 0; i < MMAX; i++)
		for (int j = 0; j < MMAX; j++)
			v[i][j] = 0;
	for (int i = 0; i < MMAX; i++)
	{
		v[i] = Tiling(v, i);
	}
	int N;
	while (cin >> N)
	{
		string str = "";
		int idx = MMAX - 1;
		while (v[N][idx] == 0)
			idx--;
		while (idx >= 0)
			cout << v[N][idx--];
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
