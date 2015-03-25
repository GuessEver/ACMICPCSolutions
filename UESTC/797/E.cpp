#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 40010;
const double eps = 1e-9, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n;
int sgn(double x)
{
    if(x < -eps)
        return -1;
    return x > eps ? 1 : 0;
}
struct Point
{
    double x, y;
    double operator * (Point b)
    {
        return x * b.x + y * b.y;
    }
    double operator ^ (Point b)
    {
        return x * b.y - y * b.x;
    }
    Point operator - (Point b)
    {
        return (Point) {x - b.x, y - b.y};
    }
    bool operator == (Point b)
    {
        return b.x == x && b.y == y;
    }
} p[NUM], v;
bool cmp(Point a, Point b)//先比较x，后比较x均可
{
    if(sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;
    return sgn(a.y - b.y) < 0;
}

vector<Point> get_convex_hull(Point p[], int pnum)
{
    sort(p, p + pnum, cmp);
    vector<Point> res(2 * pnum + 5);
    int i, total = 0, limit = 1;
    for(i = 0; i < pnum; i++)//扫描下凸壳
    {
        while(total > limit && sgn((res[total - 1] - res[total - 2]) ^ (p[i] - res[total - 1])) <= 0) total--;
        res[total++] = p[i];
    }
    limit = total;
    for(i = pnum - 2; i >= 0; i--)//扫描上凸壳
    {
        while(total > limit && sgn((res[total - 1] - res[total - 2]) ^ (p[i] - res[total - 1])) <= 0) total--;
        res[total++] = p[i];
    }
    if(total > 1)total--;//最后一个点和第一个点一样
    res.resize(total);
    return res;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    scanf("%lf%lf", &v.x, &v.y);
    p[n] = v;
    vector<Point> vpp = get_convex_hull(p, n);
    vector<Point> vp = get_convex_hull(p, n + 1);
    Point vb, ve;
    int num = vp.size();
    for(i = 0; i < vp.size(); i++)
        if(vp[i] == v)
            break;
    vb = vp[(i - 1 + num) % num], ve = vp[(i + 1) % num];
    double ans = 0;
    for(i = 0; i < n; i++)
        if(vb == vpp[i])
            break;
    if(sgn((vpp[(i + 1) % n] - vpp[i]) ^ (v - vpp[i])) == 0)
        i++;
    ans = 0;
    for(;;)
    {
        j = i + 1;
        if(j >= n) j -= n;
        if(vpp[j] == ve)
        {
            if(sgn((vpp[i] - vpp[j]) ^ (vpp[i] - v)) != 0)
                ans += sqrt((vpp[i] - vpp[j]) * (vpp[i] - vpp[j]));
        }
        else
            ans += sqrt((vpp[i] - vpp[j]) * (vpp[i] - vpp[j]));
        if(vpp[j] == ve)
            break;
        else
            i = j;
    }
    printf("%.3f", ans);
    return 0;
}

