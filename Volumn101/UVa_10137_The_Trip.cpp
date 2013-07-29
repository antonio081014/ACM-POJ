//Wed Mar  2 22:25:41 CST 2011
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

int main(int argc, char* argv[]) {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n && n) {
        vector<double> v(n);
        double amount = 0.0;
        double adds = 0.0;
        double minus = 0.0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            amount += v[i];
        }
        amount /= n;
        amount = (double) ((int) (amount * 100 + 0.5) / 100.0);
        for (int i = 0; i < n; i++) {
            if (v[i] > amount) adds += v[i] - amount;
            else minus += amount - v[i];
        }
        cout << "$";
        cout << fixed << setprecision(2) << min(adds, minus) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
