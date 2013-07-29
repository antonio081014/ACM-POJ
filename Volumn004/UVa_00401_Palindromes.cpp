//Mon Mar  8 15:51:39 CST 2010
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
//To get the reverse of that character. Pretty much like a table.
char mirroredChar(char a)
{
	switch (a)
	{
	case 'A':
		return 'A';
	case 'E':
		return '3';
	case 'H':
		return 'H';
	case 'I':
		return 'I';
	case 'J':
		return 'L';
	case 'L':
		return 'I';
	case 'M':
		return 'M';
	case 'O':
		return 'O';
	case 'S':
		return '2';
	case 'T':
		return 'T';
	case 'U':
		return 'U';
	case 'V':
		return 'V';
	case 'W':
		return 'W';
	case 'X':
		return 'X';
	case 'Y':
		return 'Y';
	case 'Z':
		return '5';
	case '1':
		return '1';
	case '2':
		return 'S';
	case '3':
		return 'E';
	case '5':
		return 'Z';
	case '8':
		return '8';
	default:
		return '$';
	}
}
//To check whether it's a regular palindrome or not.
bool isPalindrome(string str)
{
	string ss = str;
	reverse(ss.begin(), ss.end());
	if (ss == str)
		return true;
	return false;
}
//To check whether it's a mirrored string or not.
bool isMirrored(string str)
{
	string ss(str);
	for (int i = 0; i < ss.size(); i++)
	{
		ss[i] = mirroredChar(ss[i]);
	}
	reverse(ss.begin(), ss.end());
	if(ss == str) return true;
	return false;
}

int main(int argc, const char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	while (cin >> str)
	{
		bool flag1 = isPalindrome(str);
		bool flag2 = isMirrored(str);
		if (!flag1 && !flag2)
			cout << str << " -- is not a palindrome." << endl;
		else if (flag1 && !flag2)
			cout << str << " -- is a regular palindrome." << endl;
		else if (!flag1 && flag2)
			cout << str << " -- is a mirrored string." << endl;
		else
			cout << str << " -- is a mirrored palindrome." << endl;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
