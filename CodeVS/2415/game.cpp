#include<cstdio>
#include<cstring>
#include<bitset>
using std::bitset;
const int N=1000000+10;
 
int n;
struct Link{int y;Link *next;}*head[N];
int pre[N];
bitset<N> h;
 
void inlink(int x,int y)
{
    Link *tmp=new Link;
    tmp->y=y;
    tmp->next=head[x];
    head[x]=tmp;
}
 
void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        inlink(x,i);
        inlink(y,i);
    }
}
 
bool search(int x)
{
    for(Link *p=head[x];p;p=p->next)
        if(!h[p->y])
        {
            h[p->y]=1;
            if(pre[p->y]==-1 || search(pre[p->y]))
            {
                pre[p->y]=x;
                return 1;
            }
        }
    return 0;
}
 
void work()
{
    int res=0;
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        //memset(h,0,sizeof(h));
        h.reset();
        if(search(i)) res++;
        else break;
    }
    printf("%d\n",res);
}
 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    read();
    work();
    return 0;
}
