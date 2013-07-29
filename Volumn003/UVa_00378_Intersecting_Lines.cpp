//Fri Mar 11 20:27:29 CST 2011
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

const double ERR = 0.000001;

/*
 * ax + by = c
 * 
 */
class Line
{
public:
    double a;
    double b;
    double c;

    Line(double x1, double y1, double x2, double y2)
    {
        if (x1 != x2 && y1 == y2)
        {
            a = 0.0;
            b = 1.0;
            c = y1;
        }
        else if (x1 == x2 && y1 != y2)
        {
            a = 1.0;
            b = 0.0;
            c = x1;
        }
        else
        {
            a = (y1 - y2) / (x1 - x2);
            b = -1.0;
            c = x1 * (y2 - y1) / (x2 - x1) - y1;
        }
    }

    void check(Line other)
    {
        //Same slope;
        if (fabs(this->a * other.b - this->b * other.a) <= ERR)
        {

            if ((fabs(this->a * other.c - other.a * this->c) <= ERR) && (fabs(other.c * this->b - this->c * other.b) <= ERR))
            {
                cout << "LINE" << endl;
                return;
            }
            else
            {
                cout << "NONE" << endl;
                return;
            }
        }
        double x = (this->c * other.b - other.c * this->b) / (this->a * other.b - other.a * this->b);
        double y = (this->c * other.a - other.c * this->a) / (other.a * this->b - this->a * other.b);
        cout << setiosflags(ios::fixed) << setprecision(2) << "POINT " << setprecision(2) << x << " " << y << endl;
        return;
    }
};

int main(int argc, const char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cout << "INTERSECTING LINES OUTPUT" << endl;
    int N;
    cin >> N;
    while (N--)
    {
        double x1, x2, x3, x4;
        double y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Line a(x1, y1, x2, y2);
        Line b(x3, y3, x4, y4);
        a.check(b);
    }
    cout << "END OF OUTPUT" << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
