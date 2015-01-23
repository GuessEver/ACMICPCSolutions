/**************************************************************
    Problem: 2756
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:7736 ms
    Memory:2440 kb
****************************************************************/
 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 50;
const int maxpoint = 3000;
const int maxm = 100000;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
struct Edge
{
    int pos;
    long long c;
    int next;
}E[maxm];
int map[maxn][maxn],head[maxpoint];
int dis[maxpoint],gap[maxpoint],cur[maxpoint],pre[maxpoint];
int T,n,m;
int NE,s,t,nodenum;
long long maxw,cnt1,sum1,cnt2,sum2,com;
void init()
{
}
 
inline int max(long long a,long long b)
{
    return a > b ? a : b;
}
 
inline void checkmin(long long &a,long long b)
{
    if(a == -1 || a > b)a = b;
}
 
inline long long gettime(long long x)
{
    return (x * n * m - sum1 - sum2) >> 1;
}
 
void insert(int u,int v,long long c)
{
    E[NE].c = c;E[NE].pos = v;
    E[NE].next = head[u];head[u] = NE++;
    E[NE].c = 0;E[NE].pos = u;
    E[NE].next = head[v];head[v] = NE++;
}
 
long long sap()
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i = s;i <= t;i++)cur[i] = head[i];
    int u = pre[s] = s;
    long long  maxflow = 0,aug = -1;
    gap[0] = nodenum;
    while(dis[s] < nodenum)
    {
loop:  for(int &i = cur[u];i != -1;i = E[i].next)
       {
           int v = E[i].pos;
           if(E[i].c && dis[u] == dis[v] + 1)
           {
               checkmin(aug,E[i].c);
               pre[v] = u;
               u = v;
               if(v == t)
               {
                   maxflow += aug;
                   for(u = pre[u];v != s;v = u,u = pre[u])
                   {
                       E[cur[u]].c -= aug;
                       E[cur[u]^1].c += aug;
                   }
                   aug = -1;
               }
               goto loop;
           }
       }
       int mind = nodenum;
       for(int i = head[u];i != -1;i = E[i].next)
       {
           int v = E[i].pos;
           if(E[i].c && (mind > dis[v]))
           {
                cur[u] = i;
                mind = dis[v];
           }
       }
       if(--(gap[dis[u]]) == 0)break;
       gap[dis[u] = mind + 1]++;
       u = pre[u];
    }
    return maxflow;
}
 
bool check(long long x)
{
    memset(E,0,sizeof(E));
    memset(head,-1,sizeof(head));
    NE = 0,s = 0,t = n * m + 1;
    nodenum = t + 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if((i + j) & 1)
            {
                insert(s,(i - 1) * m + j,x - map[i][j]);
                if(i > 1)insert((i - 1) * m + j,(i - 2) * m + j,inf);
                if(i < n)insert((i - 1) * m + j,i * m + j,inf);
                if(j > 1)insert((i - 1) * m + j,(i - 1) * m + j - 1,inf);
                if(j < m)insert((i - 1) * m + j,(i - 1) * m + j + 1,inf);
            }
            else insert((i - 1) * m + j,t,x - map[i][j]);
        }
    }
    return ((sap() << 1) == (x * n * m - sum1 - sum2));
}
 
void solve()
{
    if(cnt1 != cnt2)
    {
        if((sum1 - sum2) % (cnt1 - cnt2) != 0)printf("-1\n");
        else
        {
            long long x = (sum1 - sum2) / (cnt1 - cnt2);
            if(x < maxw)
            {
                printf("-1\n");
                return;
            }
            if(check(x))printf("%lld\n",gettime(x));
            else printf("-1\n");
        }
    }
    else
    {
        long long l = maxw,r = inf;
        while(l < r)
        {
            long long m = (l + r) >> 1;
            if(check(m))r = m;
            else l = m + 1;
        }
        if(check(r))printf("%lld\n",gettime(r));
        else printf("-1\n");
    }
}
 
void readdata()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(map,0,sizeof(map));
        maxw = 0,sum1 = 0,cnt1 = 0,sum2 = 0,cnt2 = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                scanf("%d",&map[i][j]);
                if((i + j) & 1)cnt1++,sum1 += map[i][j];
                else cnt2++,sum2 += map[i][j];
                maxw = max(maxw,map[i][j]);
            }
        }
        solve();
    }
}
 
int main()
{
    init();
    readdata();
    return 0;
}
