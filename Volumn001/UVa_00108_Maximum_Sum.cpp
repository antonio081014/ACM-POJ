//Thu Mar 11 12:12:25 CST 2010
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

int MaxSum(int n, int a[])
{
	int i, max = -12800, sum = 0;
	for (i = 0; i < n; i++)
	{
		if (sum > 0)
			sum += a[i];
		else
			sum = a[i];
		if (max < sum)
			max = sum;
	}
	return max;
}
int MaxSum2(int n, int a[][100])
{
	int max = -12800;
	int b[100];
	int i, j, k;
	for (i = 0; i < n; i++) //Start from row# i.
	{
		for (j = 0; j < n; j++)
			b[j] = 0; //The sum of elements from row i to row k. j control the column.
		for (k = i; k < n; k++)
		{
			for (j = 0; j < n; j++)
				b[j] += a[k][j];
			int sum = MaxSum(n, b);
			if (max < sum)
				max = sum;
		}
	}
	return max;
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	int a[100][100];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << MaxSum2(n, a) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
