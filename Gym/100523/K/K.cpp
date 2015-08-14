#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
template<class T>
inline T IN(T &num)
{
    num = 0;
    char c = getchar(), f = 0;
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-') f = 1, c = getchar();
    while('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
    if(f) num = -num;
    return num;
}
template<class T>
inline void U(T num) {if(num < 0)putchar('-'), num = -num; if(num > 9)U(num / 10); putchar(num % 10 + '0');}
//------------------------   code   ---------------------------------//
const int NUM = 100010;
struct Point
{
    LL x, y, z;
    Point(LL _x = 0.0, LL _y = 0.0, LL _z = 0.0) {x = _x, y = _y, z = _z;}
    void in() {IN(x), IN(y), IN(z);}
    LL operator *(const Point b)const {return x * b.x + y * b.y + z * b.z;} //点积
    Point operator ^(const Point b)const {return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);}//叉积
    Point operator *(const LL b)const {return Point(x * b, y * b, z * b);}//标量乘
    Point operator + (const Point b)const {return Point(x + b.x, y + b.y, z + b.z);}//向量加
    Point operator - (const Point b)const {return Point(x - b.x, y - b.y, z - b.z);}//向量减
} p[NUM];
int n;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++) p[i].in();
    bool flag = true;
    if(n > 3)
    {
        int i = 3;
        Point normal = (p[0] - p[1]) ^ (p[1] - p[2]);
        while(i < n && normal.x == 0 && normal.y == 0 && normal.z == 0)
        {
            normal = (p[0] - p[1]) ^ (p[1] - p[i]);
            i++;
        }
        for(; flag && i < n; i++)
            if(normal * (p[i] - p[0]))
                flag = false;
    }
    if(flag) puts("TAK");
    else puts("NIE");
    return 0;
}
