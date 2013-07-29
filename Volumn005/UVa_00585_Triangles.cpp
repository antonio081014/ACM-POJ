//Fri Jun 18 23:56:59 CDT 2010
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

int main(int argc, char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	int ncase = 1;
	while (cin >> N && N)
	{
		vector<string> v(N, string(2 * N - 1, 'b'));
		vector<vector<int> > count1(N, vector<int> (2 * N - 1, 0));
		vector<vector<int> > count2(N, vector<int> (2 * N - 1, 0));
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < 2 * N - 1 - i; j++)
			{
				cin >> v[i][j];
			}
		}
		int mmax = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < 2 * N - 1 - i; j += 2)
			{
				if (v[i][j] == '-')
					count1[i][j] = 1;
				if (i - 1 >= 0)
				{
					if (v[i - 1][j] == '-' && v[i - 1][j - 1] == '-'
							&& v[i - 1][j + 1] == '-')
					{
						count1[i][j] += min(count1[i - 1][j - 1],
								count1[i - 1][j + 1]);
					}
				}
				mmax = max(count1[i][j], mmax);
			}
		}
		for (int i = N - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < 2 * N - 1 - i; j += 2)
			{
				if (v[i][j] == '-')
					count2[i][j] = 1;
				if (i + 1 < N && v[i + 1][j - 1] == '-' && v[i + 1][j] == '-'
						&& v[i + 1][j + 1] == '-')
					count2[i][j] += min(count2[i + 1][j - 1], count2[i + 1][j
							+ 1]);
				mmax = max(mmax, count2[i][j]);
			}
		}
		cout << "Triangle #" << ncase++ << endl;
		cout << "The largest triangle area is " << mmax * mmax << "." << endl;
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
