//Tue Mar  9 03:47:45 CST 2010
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

int main(int argc, const char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string a, b;
	vector<vector<int> > v(1001, vector<int>(1001));
	//Don't forget the situation when the input is a blank line.
	while(getline(cin, a) && getline(cin, b))
	{
		for(int i=0; i<=a.size(); i++)
		{
			for(int j=0; j<=b.size(); j++)
			{
				if(i==0 || j==0)
					v[i][j] = 0;
				else if(a[i-1] == b[j-1])
					v[i][j] = v[i-1][j-1] + 1;
				else
					v[i][j] = max(v[i-1][j], v[i][j-1]);
			}
		}
		cout << v[a.size()][b.size()] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
