/**************************************************************
    Problem: 1834
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:56 ms
    Memory:1776 kb
****************************************************************/
 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=5000+10;
const int M=40000+10;
const int inf=0x3f3f3f3f;
 
int n,m,K;
int x[N],y[N],flow[N],cost[N];
struct EG{int from,to,flow,cost,next;}edge[M];
int head[N],L;
int S,T;
int dist[N],h[N],pre[N];
queue<int> q;
 
void addedge(int a,int b,int c,int d)
{
    edge[L]=(EG){a,b,c,+d,head[a]};
    head[a]=L++;
    edge[L]=(EG){b,a,0,-d,head[b]};
    head[b]=L++;
}
 
void read()
{
    scanf("%d%d%d",&n,&m,&K);
    memset(head,-1,sizeof(head));L=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&flow[i],&cost[i]);
        addedge(x[i],y[i],flow[i],0);
    }
    S=1;T=n;
}
 
bool spfa()
{
    memset(h,0,sizeof(h));
    memset(dist,0x3f,sizeof(dist));
    dist[S]=0;q.push(S);h[S]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();h[x]=false;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            if(edge[i].flow>0 && dist[edge[i].to]>dist[x]+edge[i].cost)
            {
                pre[edge[i].to]=i;
                dist[edge[i].to]=dist[x]+edge[i].cost;
                if(!h[edge[i].to])
                {
                    h[edge[i].to]=true;
                    q.push(edge[i].to);
                }
            }
        }
    }
    return dist[T]!=inf;
}
 
int solve(int op)
{
    int mincost=0,maxflow=0;
    while(spfa())
    {
        //printf("dist=%d\n",dist[T]);
        int res=inf;
        for(int i=T;i!=S;i=edge[pre[i]].from)
        {
            res=min(res,edge[pre[i]].flow);
        }
        for(int i=T;i!=S;i=edge[pre[i]].from)
        {
            edge[pre[i]].flow-=res;
            edge[pre[i]^1].flow+=res;
        }
        maxflow+=res;
        mincost+=res*dist[T];
    }
    if(op==1) return maxflow;
    else return mincost;
}
 
void work()
{
    printf("%d ",solve(1));
    for(int i=1;i<=m;i++) addedge(x[i],y[i],K,cost[i]);
    S=0; addedge(S,1,K,0);
    printf("%d\n",solve(2));
}
 
int main()
{
    read();
    work();
    return 0;
}
