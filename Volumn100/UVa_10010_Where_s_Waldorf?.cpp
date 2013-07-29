//Wed Mar 16 17:25:32 CDT 2011
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
    int m, n;
    char c;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            s += tolower(c);
        }
        v.push_back(s);
    }
}

bool horizontal1(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    if (grid[x].substr(y).size() < sz) return false;
    if (grid[x].substr(y, sz) == str) return true;
    return false;
}

bool horizontal2(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    if (y + 1 < sz) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x][y - i])
            return false;
    return true;
    ;
}

bool vertical1(vector<string> grid, int x, int y, string str)
{
    int m = grid.size();
    int sz = str.size();
    if (x + sz > m) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x + i][y])
            return false;
    return true;
}

bool vertical2(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    if (x + 1 < sz) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x - i][y])
            return false;
    return true;
}

//left-top 2 bottom-right;

bool diagonal1(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    int m = grid.size();
    int n = grid[0].size();
    if (x + sz > m || y + sz > n) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x + i][y + i])
            return false;
    return true;
}

//right-top 2 left-bottom;

bool diagonal2(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    int m = grid.size();
    if (y + 1 < sz) return false;
    if (x + sz > m) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x + i][y - i])
            return false;
    return true;
}

//reverse of diag1;

bool diagonal3(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    if (y + 1 < sz) return false;
    if (x + 1 < sz) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x - i][y - i])
            return false;
    return true;
}

//reverse of diag2;

bool diagonal4(vector<string> grid, int x, int y, string str)
{
    int sz = str.size();
    int n = grid[0].size();
    if (x + 1 < sz) return false;
    if (y + sz > n) return false;
    for (int i = 0; i < sz; i++)
        if (str[i] != grid[x - i][y + i])
            return false;
    return true;
}

bool check(vector<string> grid, int x, int y, string str)
{
    if (horizontal1(grid, x, y, str)) return true;
    if (horizontal2(grid, x, y, str)) return true;
    if (vertical1(grid, x, y, str)) return true;
    if (vertical2(grid, x, y, str)) return true;
    if (diagonal1(grid, x, y, str)) return true;
    if (diagonal2(grid, x, y, str)) return true;
    if (diagonal3(grid, x, y, str)) return true;
    if (diagonal4(grid, x, y, str)) return true;
    return false;
}

void solveWord(vector<string> grid, string str)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (check(grid, i, j, str))
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
}

void solve(vector<string> grid)
{
    int k;
    cin >> k;
    string str;
    for (int i = 0; i < k; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            str[j] = tolower(str[j]);
        solveWord(grid, str);
    }
    return;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        if (i > 0) cout << endl;
        vector<string> grid;
        initialize(grid);
        solve(grid);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
