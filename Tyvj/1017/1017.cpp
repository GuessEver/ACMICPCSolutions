/*
C++ Code
http://blog.csdn.net/jiangzh7
By jiangzh
*/
#include<cstdio>
#define MAXN 1010

int n,m;
int f[MAXN];

int find(int x)
{
    if(f[x]==x)return x;
    f[x]=find(f[x]);
    return f[x];
}

void merge(int x,int y)
{
    int rx=find(x),ry=find(y);
    f[rx]=ry;
}

int main()
{
    freopen("ty1017.in","r",stdin);
    freopen("ty1017.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m+10;i++)f[i]=i;
    int x,y,ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if(find(x)==find(y)) ans++;
        else merge(x,y);
    }
    printf("%d\n",ans);
    return 0;
}

