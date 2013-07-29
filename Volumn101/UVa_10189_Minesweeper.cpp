//Wed Mar  2 00:58:07 CST 2011
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

char check(vector<string> v, int x, int y) {
    int ret = 0;
    int m = v.size();
    int n = v[0].size();
    if (v[x][y] == '*') return v[x][y];
    else {
        if (x > 0 && v[x - 1][y] == '*') ret++;
        if (x > 0 && y > 0 && v[x - 1][y - 1] == '*') ret++;
        if (y > 0 && v[x][y - 1] == '*') ret++;
        if (x + 1 < m && y > 0 && v[x + 1][y - 1] == '*') ret++;
        if (x + 1 < m && v[x + 1][y] == '*') ret++;
        if (x + 1 < m && y + 1 < n && v[x + 1][y + 1] == '*') ret++;
        if (y + 1 < n && v[x][y + 1] == '*') ret++;
        if (x > 0 && y + 1 < n && v[x - 1][y + 1] == '*') ret++;
    }
    return '0' + ret;
}

int main(int argc, char* argv[]) {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int m, n;
    int counter = 0;
    while (cin >> m >> n && (m + n)) {
        if (++counter > 1) cout << endl;
        vector<string> v1(m, string(n, '0'));
        for (int i = 0; i < m; i++) {
            cin >> v1[i];
        }
        cout << "Field #" << counter << ":" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << check(v1, i, j);
            }
            cout << endl;
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
