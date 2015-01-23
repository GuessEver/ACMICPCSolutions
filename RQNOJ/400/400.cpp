#include<cstdio>
#define MAXN 60
#define max(a,b) ((a)>(b)?(a):(b))

int n,m,a[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];

int main()
{
    //freopen("rqn400.in","r",stdin);
    //freopen("rqn400.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int t=1;t<=m;t++)
                {
                    f[i][j][k][t] = max( f[i][j][k][t], f[i-1][j][k-1][t] );
                    f[i][j][k][t] = max( f[i][j][k][t], f[i-1][j][k][t-1] );
                    f[i][j][k][t] = max( f[i][j][k][t], f[i][j-1][k-1][t] );
                    f[i][j][k][t] = max( f[i][j][k][t], f[i][j-1][k][t-1] );
                    f[i][j][k][t]+=a[i][j];
                    if(i!=k || j!=t)f[i][j][k][t]+=a[k][t];
                }
    printf("%d",f[n][m][n][m]);
    return 0;
}

