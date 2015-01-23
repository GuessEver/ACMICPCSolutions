#include<cstdio>
#define MAXN 110
#define max(a,b) ((a)>(b)?(a):(b))

int n,rmb[MAXN],rp[MAXN],t[MAXN],m,r;
int f[MAXN][MAXN],g[MAXN][MAXN];

int main()
{
    //freopen("ty1013.in","r",stdin);
    //freopen("ty1013.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&rmb[i],&rp[i],&t[i]);
    scanf("%d%d",&m,&r);
    
    for(int i=1;i<=n;i++)
        for(int j=m;j>=rmb[i];j--)
            for(int k=r;k>=rp[i];k--)
                if((g[j][k]<g[j-rmb[i]][k-rp[i]]+1)||
                (g[j][k]==g[j-rmb[i]][k-rp[i]]+1 && f[j][k]>f[j-rmb[i]][k-rp[i]]+t[i]))
                {
                    g[j][k]=g[j-rmb[i]][k-rp[i]]+1;
                    f[j][k]=f[j-rmb[i]][k-rp[i]]+t[i];
                }

    int minx=0x7fffffff,maxx=0;
    
    for(int j=m;j>=0;j--)
        for(int k=r;k>=0;k--)
            if((g[j][k]>maxx)||(g[j][k]==maxx && f[j][k]<minx))
            {
                minx=f[j][k];
                maxx=g[j][k];
            }
            
    printf("%d",minx);

    
    return 0;
}

