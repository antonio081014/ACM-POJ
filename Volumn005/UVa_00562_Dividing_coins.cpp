//Thu Mar 11 16:15:37 CST 2010
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

vector<vector<int> > v(101, vector<int> (25001, 0));
//Up to use i elements, the maximum sum smaller than j;

vector<int> weight;

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	while (n--)
	{
		weight.clear();
		weight.push_back(0);
		int m;
		cin >> m;
		int sum = 0;
		for (int i = 1; i <= m; i++)
		{
			int tmp;
			cin >> tmp;
			weight.push_back(tmp);
			sum += weight[i];
		}
		sort(weight.begin(), weight.end());
		//		for(int i=0; i<=m; i++) cout << weight[i] << " ";
		//		cout << endl;
		int half = sum / 2;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= half; j++)
			{
				v[i][j] = max(v[i][j - 1], v[i - 1][j]);
//				if (j >= weight[i])
					v[i][j] = max(v[i][j], (j>=weight[i] ? v[i - 1][j - weight[i]] + weight[i] : 0));
			}
		}
		cout << abs(sum - 2 * v[m][half]) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
