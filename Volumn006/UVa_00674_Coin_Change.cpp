//Wed Mar 10 05:34:57 CST 2010
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
//This is a Coin Change DP straight-up. Just build the table beforehand, and then output the answer from the table each time.
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
			v[i][j] = v[i - 1][j]
					+ (j >= dollars[i] ? v[i][j - dollars[i]] : 0);
		}
	}
	int m;
	while (cin >> m)
	{
		cout << v[5][m] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 * Test data:
 * 4
 * 13
 */
 */
