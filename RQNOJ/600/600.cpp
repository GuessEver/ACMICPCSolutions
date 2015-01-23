#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 20010
#define INF 0x77777777

struct link{int y,z;link *next;};
int n,m,c[MAXN];
link *head[MAXN];
queue<int> q;

void insert(int x,int y,int z)
{
    link *node=new link;
    node->y=y;
    node->z=z;
    node->next=head[x];
    head[x]=node;
}

int check(int mid)
{
    memset(c,0,sizeof(c));
    while(!q.empty())q.pop();
    for(int k=1;k<=n;k++)
        if(!c[k])
        {
            c[k]=1;//染色
            q.push(k);//入队
            while(!q.empty())
            {
                int i=q.front();q.pop();
                link *node=head[i];
                while(node)
                {
                    int y=node->y,z=node->z;
                    if(z>mid)//仇恨值大于mid，所以不能在同一监狱
                    {
                        if(!c[y]) {c[y]=3-c[i];q.push(y);}//染成不同颜色   入队
                        else if(c[y]==c[i]) return 0;//本不应在同一监狱  但是染色相同  矛盾  返回'否'
                    }
                    node=node->next;
                }
            }
        }
    return 1;
}

int main()
{
    //freopen("prison.in","r",stdin);
    //freopen("prison.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i,x,y,z;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        insert(x,y,z);
        insert(y,x,z);
    }
    int l=0,r=INF,mid;
    while(l+1<r)
    {
        mid=l+(r-l)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    int ans=r;
    if(check(l))ans<?=l;
    printf("%d",ans);
    return 0;
}

