//Fri Mar 18 02:32:09 CDT 2011
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

class Job
{
public:
    int ID;
    int times;
    int fines;

    Job(int id, int t, int f)
    {
        this->ID = id;
        this->times = t;
        this->fines = f;
    }

    static bool cmp(const Job &A, const Job &B)
    {
        if (A.fines * B.times > A.times * B.fines) return true;
        if (A.fines * B.times == A.times * B.fines) return A.ID < B.ID;
        return false;
    }
};

void initialize(int N, vector<Job> &v)
{
    for (int i = 0; i < N; i++)
    {
        int t, f;
        cin >> t >> f;
        v.push_back(Job(i + 1, t, f));
    }
}

void solve(int N, vector<Job> v)
{
    std::sort(v.begin(), v.end(), Job::cmp);
    cout << v[0].ID;
    for (int i = 1; i < N; i++)
        cout << " " << v[i].ID;
    cout << endl;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        if (k > 0) cout << endl;
        int N;
        cin >> N;
        vector<Job> maker;
        initialize(N, maker);
        solve(N, maker);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
