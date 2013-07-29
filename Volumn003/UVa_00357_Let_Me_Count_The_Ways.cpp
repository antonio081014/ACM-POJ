//Tue Mar  9 23:59:39 CST 2010
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
//The coin counting problem.
int dollars[] =
{ 0, 1, 5, 10, 25, 50 };
vector<vector<long long> > v(6, vector<long long> (30001, 0));
int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 6; i++)
		v[i][0] = 1;
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j <= 30000; j++)
		{
			v[i][j] = v[i - 1][j] + (j >= dollars[i] ? v[i][j - dollars[i]] : 0);
		}
	}
	int m;
	while (cin >> m)
	{
		if (v[5][m] == 1)
			cout << "There is only 1 way to produce " << m << " cents change."
					<< endl;
		else
			cout << "There are " << v[5][m] << " ways to produce " << m
					<< " cents change." << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 * The test data I tried:
 * 30000
 * 0
 * 17
 * 11
 * 4*/
