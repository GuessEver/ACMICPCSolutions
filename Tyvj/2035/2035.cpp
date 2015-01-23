/*
C++ Code
http://oijzh.cnblogs.com
By jiangzh
*/
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
struct link{int y;link *next;};
link *head[1010];
bool h[1010];
bool flag;

void insert(int x,int y)
{
    link *node=new link;
    node->y=y;
    node->next=head[x];
    head[x]=node;
}

void work(int x,int std)
{
    link *node=head[x];
    while(node)
    {
        if(node->y==std){flag=true;return;}
        if(!h[node->y])
        {
            h[node->y]=true;
            work(node->y,std);
        }
        node=node->next;
    }
}

int main()
{
    //freopen("P2035.in","r",stdin);
    //freopen("P2035.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        insert(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        memset(h,0,sizeof(h));
        flag=false;
        work(i,i);
        if(flag)printf("T\n");else printf("F\n");
    }
    return 0;
}

