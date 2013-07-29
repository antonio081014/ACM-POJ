//Tue Mar  9 02:51:35 CST 2010
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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	vector<string> v(100, string(100, '*'));
	string str;
	int count = 0;
	int maxlen = 0;
	while(getline(cin, str))
	{
		for(int i=0; i<(int)str.size(); i++)
		{
			v[i][count] = str[i];
		}
		maxlen = max((int)str.size(), maxlen);
		count ++;
	}
	for(int i=0; i<maxlen; i++)
	{
		for(int j=count-1; j>=0; j--)
		{
			cout << (v[i][j]=='*' ? ' ' : v[i][j]);
		}
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
