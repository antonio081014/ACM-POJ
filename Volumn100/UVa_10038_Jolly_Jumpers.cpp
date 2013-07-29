//Mon Mar 14 01:04:00 CDT 2011
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
    int N;
    while (cin >> N)
    {
        vector<int> v(N, 0);
        set<int> diff;
        set<int>::iterator it;
        for (int i = 0; i < N; i++)
            cin >> v[i];
        for (int i = 1; i < N; i++)
            diff.insert(abs(v[i] - v[i - 1]));
        
        if ((int) diff.size() != N - 1)
        {
            cout << "Not jolly" << endl;
            continue;
        }

        int count = 1;
        bool flag = true;
        for (it = diff.begin(); it != diff.end(); it++, count++)
        {
            if ((int) (*it) != count)
            {
                flag = false;
                break;
            }
        }
        if (flag && count == N)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
