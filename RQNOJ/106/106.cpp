#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110
#define INF 0x7fffffff

int n,a[MAXN][MAXN],sum[MAXN][MAXN];//sum[i][j]表示第j列前i行之和
int f[MAXN];

int main()
{
    //freopen("rqn106.in","r",stdin);
    //freopen("rqn106.out","w",stdout);
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            sum[i][j]=sum[i-1][j]+a[i][j];
    int k,maxx=-INF;
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                int cc=sum[j][k]-sum[i-1][k];
                f[k]=max(f[k-1]+cc,cc);
                maxx>?=f[k];
            }
    printf("%d",maxx);
    return 0;
}

