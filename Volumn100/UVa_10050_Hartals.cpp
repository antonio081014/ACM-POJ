//Mon Mar 14 14:17:16 CDT 2011
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

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int N, P;
        cin >> N >> P;
        vector<bool> flag(N, false);
        int days;
        for (int k = 0; k < P; k++)
        {
            cin >> days;
            for (int i = days-1; i < N; i += days)
                flag[i] = true;
        }
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (i % 7 != 5 && i % 7 != 6 && flag[i])
                count++;
        }
        cout << count << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
