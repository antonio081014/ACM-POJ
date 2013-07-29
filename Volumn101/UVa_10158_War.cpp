//Wed Jun  9 23:10:38 CDT 2010
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
#define MMAX 10000
using namespace std;

class War
{
public:
	int parent;
	int rank; //0, means friends; otherwise, enemy;
};

vector<War> v(MMAX);

void Makeset(int N)
{
	for (int i = 0; i <= N; i++)
	{
		v[i].parent = i;
		v[i].rank = 0;
	}
}

int Find(int x)
{
	if (x == v[x].parent)
		return x;
	int temp = v[x].parent;
	v[x].parent = Find(temp);
	//	v[x].rank = v[temp].rank == 0 ? v[x].rank : (1 - v[x].rank);
	//	int temp = Find(v[x].parent);
	v[x].rank = (v[x].rank + v[temp].rank) & 1;
	//	v[x].parent = temp;
	return v[x].parent;
}

void Union(int t1, int t2, int x, int y, int d)
{
	v[t2].parent = t1;
	//v[t2].rank = v[x].rank == v[y].rank ? d : (1 - d);
	v[t2].rank = (v[x].rank + v[y].rank + d) & 1;
	Find(x);
}

int Judge(int t1, int t2, int x, int y)
{
	if (t1 == t2)
	{
		if (v[x].rank == v[y].rank)
			return 0; //Friends;
		else
			return 1; //Enemy;
	}
	return -1;
}

int main(int argc, char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	Makeset(N);
	int a, b, c;
	while (cin >> a >> b >> c && (a + b + c))
	{
		int t1, t2;
		if (a == 1)
		{
			t1 = Find(b);
			t2 = Find(c);
			if (Judge(t1, t2, b, c) == 1)
				cout << -1 << endl;
			else
				Union(t1, t2, b, c, 0);
		}
		else if (a == 2)
		{
			t1 = Find(b);
			t2 = Find(c);
			if (Judge(t1, t2, b, c) == 0)
				cout << -1 << endl;
			else
				Union(t1, t2, b, c, 1);
		}
		else if (a == 3)
		{
			t1 = Find(b);
			t2 = Find(c);
			if (Judge(t1, t2, b, c) == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (a == 4)
		{
			t1 = Find(b);
			t2 = Find(c);
			if (Judge(t1, t2, b, c) == 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
