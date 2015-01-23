#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=10000+10;

int n,m;
struct link{int y;link *next;}*head[N];
stack<int> st;
bool hash[N],inst[N];
int dfstime;
int low[N],now[N];
int number;


void inlink(int x,int y)
{
    link *node=new link;
    node->y=y;
    node->next=head[x];
    head[x]=node;
}

void dfs(int x)
{
    now[x]=low[x]=++dfstime;
    hash[x]=true;st.push(x);inst[x]=true;
    for(link *node=head[x];node;node=node->next)
    {
        int y=node->y;
        if(!hash[y])
        {
            dfs(y);
            low[x]=min(low[x],low[y]);
        }
        else if(inst[y]) low[x]=min(low[x],now[y]);
    }
    if(now[x]==low[x])
    {
        while(!st.empty())
        {
            int u=st.top();st.pop();
            inst[u]=false;
            if(u==x) break;
        }
        number++;
    }
}

void tarjan()
{
    for(int i=1;i<=n;i++) if(!hash[i]) dfs(i);
    if(!st.empty())
    {
        while(!st.empty())
        {
            int u=st.top();st.pop();
            inst[u]=false;
        }
        number++;
    }
}

void work()
{
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        inlink(x,y);
    }
    tarjan();
    if(number==1) puts("Yes");
    else puts("No");
}

int main()
{
    freopen("1269.in","r",stdin);
    freopen("1269.out","w",stdout);
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        number=dfstime=0;
        memset(hash,0,sizeof(hash));
        memset(now,0,sizeof(now));
        memset(low,0,sizeof(low));
        memset(head,0,sizeof(head));
        work();
    }
    //while(1);
    return 0;
}
