//Wed Mar 16 22:14:38 CDT 2011
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

string solve(string s1, string s2)
{
    string str = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (isalpha(s1[i]) == false) continue;
        int found = s2.find(s1[i]);
        if (found != string::npos)
        {
            str += s1[i];
            s2[found] = '.';
        }
    }
    std::sort(str.begin(), str.end());
    return str;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    char s1[1001], s2[1001];
    while (gets(s1))
    {
        //getchar();
        gets(s2);
        //getchar();
        cout << solve(string(s1), string(s2)) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
