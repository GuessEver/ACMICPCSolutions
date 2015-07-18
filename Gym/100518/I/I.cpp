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
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
struct node
{
    LL d, p;
    int id;
    void in(int i)
    {
        id = i;
        scanf("%I64d%I64d", &d, &p);
    }
} ex[NUM];
struct Tour
{
    LL s, t;
    void in() {scanf("%I64d%I64d", &s, &t);}
} tour[NUM];;
int n, m;
bool operator < (node a, node b)
{
	if(a.p == b.p)
		return a.id < b.id;
    return a.p < b.p;
}
bool cmp(node a, node b)
{
	return a.d < b.d;
}
bool operator < (Tour a, Tour b)
{
    return a.t < b.t;
}
LL sum, num;
int ans[NUM], ansn;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("intelligent.in", "r", stdin);
    freopen("intelligent.out", "w", stdout);
#endif
    int i, j;
    while(~scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++)
            ex[i].in(i);
        scanf("%d", &m);
        for(i = 0; i < m; i++)
            tour[i].in();
        sort(ex + 1, ex + 1 + n, cmp);
        sort(tour, tour + m);
        ex[0].d = 1;
        sum = num = 0;
        priority_queue<node> que;
        while(!que.empty()) que.pop();
        for(i = 1, j = 0; i <= n; i++)
        {
            sum += ex[i].d - ex[i - 1].d;
            while(j < m && tour[j].t < ex[i].d)
            {
                sum -= tour[j].t - tour[j].s + 1;
                j++;
            }
            // cout << sum << endl;
            if(num + ex[i].p <= sum)
            {
                num += ex[i].p + 1;
                que.push(ex[i]);
            }
            else
            {
                num += ex[i].p;
                que.push(ex[i]);
                num -= que.top().p;
                que.pop();
            }
        }
        ansn = 0;
        while(!que.empty())
        {
            ans[ansn++] = que.top().id;
            que.pop();
        }
        sort(ans, ans + ansn);
        printf("%d\n", ansn);
        if(ansn > 0) printf("%d", ans[0]);
        for(i = 1; i < ansn; i++)
            printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}
