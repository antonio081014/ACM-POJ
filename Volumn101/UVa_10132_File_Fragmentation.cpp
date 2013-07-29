//Thu Mar 17 15:57:46 CDT 2011
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

void initialize(vector<string> &v)
{
    string str;
    while (getline(cin, str, '\n'))
    {
        if (str == "") break;
        //cout << str << endl;
        v.push_back(str);
    }
}

bool cmp(const string &A, const string &B)
{
    int szA = A.size();
    int szB = B.size();
    if (szA < szB) return true;
    if (szA == szB && A.compare(B) < 0)
        return true;
    return false;
}

bool check(vector<string> v, string str)
{
    for (int i = 0; i < v.size(); i++)
    {
        int found1 = str.find(v[i]);
        int found2 = str.rfind(v[i]);
        if (found1 != 0 && found2 + v[i].size() != str.size()) return false;
    }
    return true;
}

string solve(vector<string> v)
{
    int szmin = v[0].size();
    int szmax = v[v.size() - 1].size();
    for (int i = 0; v[i].size() == szmin; i++)
        for (int j = v.size() - 1; v[j].size() == szmax; j--)
        {
            string str = v[i] + v[j];
            if (check(v, str))
                return str;
            str = v[j] + v[i];
            if (check(v, str))
                return str;
        }
    return "";
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    getchar();
    getchar();
    for (int ncase = 1; ncase <= T; ncase++)
    {
        if (ncase > 1) cout << endl;
        vector<string> frags;
        initialize(frags);
        std::sort(frags.begin(), frags.end(), cmp);
        cout << solve(frags) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
