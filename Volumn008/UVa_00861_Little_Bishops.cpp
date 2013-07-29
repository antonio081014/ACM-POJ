//Tue Apr  5 00:46:15 CDT 2011
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

void init(int n, vector<int> &black, vector<int> &white)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) % 2)
                white[(i + j) / 2]++;
            else
                black[(i + j) / 2]++;
        }
    }
}

void bishops(int n, int k, vector<vector<int> > &dp, vector<int> color)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= k; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= color[i] && j<=k; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (color[i] - j + 1);
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, k;
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0) return 0;
        vector<vector<int> > dp1(n + 1, vector<int>(k + 1, 0));
        vector<vector<int> > dp2(n, vector<int>(k + 1, 0));
        vector<int> white(n, 0);
        vector<int> black(n + 1, 0);
        init(n, black, white);
        sort(black.begin() + 1, black.end());
        sort(white.begin() + 1, white.end());
        bishops(n, k, dp1, black);
        bishops(n - 1, k, dp2, white);
        int count = 0;
        for (int i = 0; i <= k; i++)
            count += dp1[n][i] * dp2[n-1][k - i];
        cout << count << endl;
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
