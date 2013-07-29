//Tue Mar  9 02:40:39 CST 2010
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
	string str;
	while(getline(cin, str))
	{
		int count = 0;
		bool flag = false;
		for(int i=0; i<(int)str.size(); i++)
		{
			if(isalpha(str[i]))
			{
				count += (flag==false ? 1 : 0);
				flag = true;
			}
			else
				flag = false;
		}
		cout << count << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
