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
#include <deque>
#include <stack>
#include <climits>
#include <bitset>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
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
//------------------------   code   ---------------------------------//
const int maxv = 210;
int n, k, m;
bitset<maxv> g[maxv], tmp, gg[maxv];
int sum;
void pr()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << g[i][j];
        cout << endl;
    }
}
void build()
{
	for(int i = 1; i <= n; i++) g[i].reset();
    sum = 0;
    for(int i = n; i > 0; i--)
    {
        g[i].set(i);
        for(int j = 1; j < i; j++)
            if(gg[j][i])
                g[j] |= g[i];
        sum += g[i].count();
    }
}
//void add(int u, int v)
//{
//    tmp = g[u];
//    g[u] |= g[v];
//    gg[u][v] = 1;
//    if(tmp == g[u]) return ;
//    for(int i = u; i > 0; i--)
//        for(int j = 1; j < i; j++)
//            if(gg[j][i])
//                g[j] |= g[u];
//    sum = 0;
//    for(int i = 1; i <= n; i++)
//        sum += g[i].count();
//}
//void minu(int u, int v)
//{
//    gg[u][v] = 0;
//    for(int i = u; i > 0; i--)
//        g[i].reset();
//    for(int i = u; i > 0; i--)
//    {
//        g[i].set(i);
//        for(int j = i + 1; j <= n; j++)
//            if(gg[i][j])
//                g[i] |= g[j];
//    }
//    sum = 0;
//    for(int i = 1; i <= n; i++)
//        sum += g[i].count();
//}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("settling.in", "r", stdin);
    freopen("settling.out", "w", stdout);
#endif
    int i;
    int u, v;
    IN(n);
    IN(m);
    for(i = 1; i <= n; i++) g[i].reset(), gg[i].reset();
    for(i = 0; i < m; i++)
    {
        IN(u), IN(v);
        gg[u].set(v);
    }
    IN(k);
    sum = 0;
    build();
    printf("%d\n", sum - n);
    char op[2];
    while(k--)
    {
        scanf("%s%d%d", op, &u, &v);
        if(op[0] == '+')
        {
            gg[u].set(v);
            build();
            printf("%d\n", sum - n);
        }
        else if(op[0] == '-')
        {
        	gg[u].reset(v);
        	build();
            printf("%d\n", sum - n);
        }
        else
        {
            if(g[u].test(v))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
