//Tue Mar  9 14:57:01 CST 2010
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
{ 0, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
//convert the double to integer by multiplying 20.
//Using 5c as the basic unit.
vector<vector<long long> > v(12, vector<long long> (6001, 0));

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i <= 11; i++)
		v[i][0] = 1;
	for (int i = 1; i <= 11; i++)
	{
		for (int j = 1; j <= 6000; j++)
		{
			v[i][j] = v[i - 1][j] + (j >= dollar[i] ? v[i][j - dollar[i]] : 0);
			//i: using first i currency.
			//j: the sum.
			//v[i][j] just consider dollar[i], the other situations has been considered in v[i-1][j].
		}
	}
	double sum;
	while (cin >> sum && sum != 0.00)
	{
		cout << fixed;
		int S = static_cast<int> (sum * 20.0 + 0.5);
		//int S = (int)floor(sum * 20.0 + 0.5);
		//Either way will work.
		cout << setprecision(2) << setw(6) << sum;
		cout << setw(17) << v[11][S] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 * The input I tried:
 * 0.20
 * 2.00
 * 2.20
 * 300.00
 * Finally the problem is the large number, which the answer to the 300.00 is 181490736388615,
 * rather than a negative value.
 * */
