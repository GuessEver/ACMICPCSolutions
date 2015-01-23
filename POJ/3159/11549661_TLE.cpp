/*-------------------------------------------------------------------
 * Purpose:
 *         POJ 3159 candies 做了一些优化
 * Time:
 *         2012年3月21日 9:27:16
 * Author:
 *         张彦升
 -------------------------------------------------------------------*/
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int V = 30001;
const int E = 150001;

int pnt[E],cost[E],nxt[E];

int e,head[V];
int dist[V];
bool vis[V];

int relax(int u,int v,int c)
{
    if (dist[v] > dist[u] + c)
    {
        dist[v] = dist[u] + c;
        return 1;
    }
    return 0;
}
void addedge(int u,int v,int c)
{
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}
int SPFA(int src,int n)
{
    int i;
    for (i = 1;i <= n;i ++)
    {
        vis[i] = 0;
        dist[i] = INF;
    }
    dist[src] = 0;
    int Q[E],top = 1;
    Q[0] = src;
    vis[src] = true;
    while (top)
    {
        int u,v;
        u = Q[--top];
        vis[u] = false;
        for (i = head[u];i != -1;i = nxt[i])
        {
            v = pnt[i];
            if (1 == relax(u,v,cost[i]) && !vis[v])
            {
                Q[top++] = v;
                vis[v] = true;
            }
        }
    }
    return dist[n];
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        int i,a,b,c;
        e = 0;
        memset(head,-1,sizeof(head));
        for (i = 0;i < m;++i)
        {
            cin >> a >> b >> c;
            addedge(a,b,c);
        }
        cout << SPFA(1,n) << endl;
    }
    return 0;
}