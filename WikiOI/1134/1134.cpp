#include<cstdio>
#define MAXN 10010

int n,x[MAXN],y[MAXN],g[MAXN],k[MAXN],tx,ty,ans=-1;

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        scanf("%d%d%d%d",&x[i],&y[i],&g[i],&k[i]);
    scanf("%d%d",&tx,&ty);
    for(i=1;i<=n;i++)
        if(tx>=x[i] && tx<=x[i]+g[i] && ty>=y[i] && ty<=y[i]+k[i])
            ans=i;
    printf("%d",ans);
    return 0;
}
