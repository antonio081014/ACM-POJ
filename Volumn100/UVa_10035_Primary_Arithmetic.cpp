//Sat Mar 19 00:44:53 CDT 2011
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

int solve(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sz1 = s1.size();
    int sz2 = s2.size();
    if (sz1 > sz2)
        s2 += string(sz1 - sz2, '0');
    else if (sz2 > sz1)
        s1 += string(sz2 - sz1, '0');
    int ret = 0;
    int flag = 0;
    for (int i = 0; i < max(sz1, sz2); i++)
    {
        int sum = (s1[i] - '0') + (s2[i] - '0') + flag;
        flag = sum / 10;
        if (flag > 0)
            ret++;
    }
    return ret;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s1 == "0" && s2 == "0") break;
        int count = solve(s1, s2);
        if (count == 0)
            cout << "No carry operation.";
        else if (count == 1)
            cout << "1 carry operation.";
        else
            cout << count << " carry operations.";
        cout << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
