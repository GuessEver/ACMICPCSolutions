#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 100010

struct tnode{int pos;tnode* next;};
int n,m,pri[MAXN],buy[MAXN],sell[MAXN];
tnode *head[MAXN],*tile[MAXN];
bool h[MAXN];
queue<int> q;

void insert(int x,int y)
{
    tnode* node=new tnode;
    node->pos=y;
    node->next=head[x];
    head[x]=node;

    tnode* nde=new tnode;
    nde->pos=x;
    nde->next=tile[y];
    tile[y]=nde;
}

void spfabuy()
{
    while(!q.empty())q.pop();//队列清空
    q.push(1);h[1]=true;buy[1]=pri[1];
    while(!q.empty())
    {
        int x=q.front();q.pop();
        tnode* node=head[x];
        while(node)
        {
            int y=node->pos;
            if(buy[y]>min(buy[x],pri[y]))
            {
                buy[y]=min(buy[x],pri[y]);
                if(!h[y]){h[y]=true;q.push(y);}
            }
            node = node -> next;
        }
    }
}

void spfasell()
{
    while(!q.empty())q.pop();//队列清空
    q.push(n);h[n]=true;sell[n]=pri[n];
    while(!q.empty())
    {
        int x=q.front();q.pop();
        tnode* node=tile[x];
        while(node)
        {
            int y=node->pos;
            if(sell[y]<max(sell[x],pri[y]))
            {
                sell[y]=max(sell[x],pri[y]);
                if(!h[y]){h[y]=true;q.push(y);}
            }
            node = node -> next;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++) scanf("%d",&pri[i]);
    int x,y,z;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        insert(x,y);
        if(z==2)insert(y,x);
    }
    memset(buy,63,sizeof(buy));
    spfabuy();
    //for(i=1;i<=n;i++) printf("%d ",buy[i]);printf("\n");
    memset(h,0,sizeof(h));
    memset(sell,0,sizeof(sell));
    spfasell();
    //for(i=1;i<=n;i++) printf("%d ",sell[i]);printf("\n");
    int max=0;
    for(i=1;i<=n;i++) if(max<sell[i]-buy[i])max=sell[i]-buy[i];
    printf("%d",max);
    return 0;
}
