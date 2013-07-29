//Tue Mar  9 03:03:01 CST 2010
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
		if((int)str.size() == 0)
		{
			cout << endl;
			continue;
		}
		int number = 0;
		char c;
		for(int i=0; i<str.size(); i++)
		{
			if(isdigit(str[i]))
				number += str[i] - '0';
			else if(str[i] == '!') //When we should change to the newline.
			{
				cout << endl;
				number = 0;
			}
			else //When we have other characters, like letters and *.
			{
				for(int j=0; j<number; j++)
				{//Since the character 'b' here means space specially.
					cout << (str[i]=='b' ? ' ' : str[i]);
				}
				number = 0;
			}
		}
		cout << endl; //Don't forget the newline after each input line.
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
