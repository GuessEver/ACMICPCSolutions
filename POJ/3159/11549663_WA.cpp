#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
//邻接表+优先级队列+dijkstra
const int maxn=160000;
const int inf=(1<<27);
struct edge
{
    int t,w;//s->t=w;
    int next;//s->的下一个定点
};
int p[maxn];//表头结点 初值-1
edge G[maxn];//邻接表
int l;//邻接表  初值0
int V,E;//点数 边数
//添加边
void addedge(int u,int v,int w)
{
    G[l].t=v;
    G[l].w=w;
    G[l].next=p[u];
    p[u]=l++;
}
//计算从s0到其他点的最短距离
struct CNode
{
    int k,w;//s0->k=w;
};
bool operator < ( const CNode & d1, const CNode & d2 ) {
    return d1.w > d2.w;   //priority_queue总是将最大的元素出列
}
priority_queue<CNode> q;
bool vis[maxn];
int dis[maxn];//s0到其他点的最短距离
CNode tmp;//temp
void priority_queue_dijkstra(int s0)
{
    memset(vis,0,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    tmp.k=s0,tmp.w=0;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();q.pop();
        if(vis[tmp.k]) continue;
        vis[tmp.k]=true;
        dis[tmp.k]=tmp.w;
        for(int i=p[tmp.k];i!=-1;i=G[i].next)
        {
            CNode t;
            t.k=G[i].t;
            if(vis[t.k]) continue;
            t.w=tmp.w+G[i].w;
            q.push(t);
        }
    }
}
int main()
{
    while(scanf("%d%d",&V,&E)==2)
    {
        memset(p,-1,sizeof(p));//important
        l=0;//important
        for(int i=0;i<E;i++)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);//从1开始
            //u->v=w
            addedge(u,v,w);
        }
        priority_queue_dijkstra(1);
        printf("%d\n",dis[V - 2]);
    }
    return 0;
}
