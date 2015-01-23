#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 110
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define INF 0x7fffffff

int n,m,r,rmb[MAXN],rp[MAXN],t[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];

int main()
{
    //freopen("rqn57.in","r",stdin);
    //freopen("rqn57.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&rmb[i],&rp[i],&t[i]);
    scanf("%d%d",&m,&r);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=rmb[i];j--)
            for(int k=r;k>=rp[i];k--)
                if((g[j][k]<g[j-rmb[i]][k-rp[i]]+1)||(g[j][k]==g[j-rmb[i]][k-rp[i]]+1&&f[j][k]>f[j-rmb[i]][k-rp[i]]+t[i]))
                {
                    g[j][k]=g[j-rmb[i]][k-rp[i]]+1;
                    f[j][k]=f[j-rmb[i]][k-rp[i]]+t[i];
                }
    int maxx=0,minx=INF;//maxx表示最大能泡的MM数      minx表示最小的时间
    for(int j=m;j>=0;j--)
        for(int k=r;k>=0;k--)
            if((maxx<g[j][k])||(maxx==g[j][k]&&minx>f[j][k]))
            {
                maxx=g[j][k];
                minx=f[j][k];
            }
    printf("%d",minx);
    return 0;
}

