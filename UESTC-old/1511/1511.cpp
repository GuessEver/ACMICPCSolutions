#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100000+10;
typedef long long LL;
 
int n,m;
struct link{int y,z;link *next;}*head[N];
queue<int> q;
int dist[N],inQ[N];
int relax[N];
 
void inlink(int x,int y,int z)//x-y <= z
{
    link *node=new link;
    node->y=y;node->z=z;
    node->next=head[x];
    head[x]=node;
}
 
bool read()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1) // x = y
        {
            inlink(x,y,0);// x-y <= -0
            inlink(y,x,0);// y-x <= -0
        }
        else if(op==2) // x < y
        {
            if(x==y) return 0;
            inlink(x,y,1);// x-y <= -1
        }
        else if(op==3) // x >= y
            inlink(y,x,0);// y-x <= -0
        else if(op==4) // x > y
        {
            if(x==y) return 0;
            inlink(y,x,1);// y-x <= -1
        }
        else if(op==5) // x <= y
            inlink(x,y,0);// x-y <= -0
    }
    return 1;
}
 
bool spfa()
{
    memset(relax,0,sizeof(relax));
    memset(inQ,0,sizeof(inQ));
    while(!q.empty())
    {
        int x=q.front();
        q.pop(); inQ[x]=0;
        for(link *node=head[x];node;node=node->next)
            if(dist[node->y]<dist[x]+node->z)
            {
                dist[node->y]=dist[x]+node->z;
                if(++relax[node->y]>=n) return 0;//circle
                if(!inQ[node->y])
                {
                    inQ[node->y]=1;
                    q.push(node->y);
                }
            }
    }
    return 1;
}
 
LL solve()
{
    for(int i=1;i<=n;i++) 
    {//push all the points in the queue
        dist[i]=1;//every one should have at least one candy
        q.push(i); inQ[i]=1;
    }
    if(!spfa()) return -1;
    LL res=0;
    for(int i=1;i<=n;i++) res+=dist[i];
    return res;
}
 
int main()
{
    if(!read()) printf("-1\n");
    else printf("%lld\n",solve());
    return 0;
}
