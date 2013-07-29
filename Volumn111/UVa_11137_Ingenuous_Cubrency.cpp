//Thu Mar 11 12:37:52 CST 2010
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

int dollar[] =
{ 0, 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375,
		4096, 4913, 5832, 6859, 8000, 9261 };
vector<vector<long long> > v(22, vector<long long>(10001, 0));
int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for(int i=0; i<22; i++) v[i][0] = 1;
	for(int i=1; i<22; i++)
	{
		for(int j=1; j<10001; j++)
		{
			v[i][j] = v[i-1][j] + (j>=dollar[i] ? v[i][j-dollar[i]] : 0);
		}
	}
	int sum;
	while(cin >> sum)
	{
		cout << v[21][sum] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 * Test data:
 * 10
 * 21
 * 77
 * 9999
 */
