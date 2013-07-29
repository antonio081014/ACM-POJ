//Sat Mar 19 01:40:35 CDT 2011
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

bool checkPalindrom(string s)
{
    int sz = s.size();
    for (int i = 0, j = sz - 1; i <= j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

string add(string s1)
{
    int sz = s1.size();
    string s2(s1);
    reverse(s1.begin(), s1.end());
    string ret = "";
    int flag = 0;
    for (int i = 0; i < sz; i++)
    {
        int sum = (s1[i] - '0') + (s2[i] - '0') + flag;
        if (sum > 9)
        {
            flag = 1;
            sum %= 10;
        }
        else
        {
            flag = 0;
        }
        ret += '0' + sum;
    }
    if (flag == 1)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve(string s)
{
    int count = 0;
    while (checkPalindrom(s) == false)
    {
        s = add(s);
        count++;
    }
    cout << count << " " << s << endl;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int N;
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        solve(str);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
