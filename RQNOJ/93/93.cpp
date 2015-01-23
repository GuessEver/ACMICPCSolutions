#include<cstdio>
#include<cstring>
using namespace std;
#define MAXH 40
#define MAXN 60
#define max(a,b) (a)>(b)?(a):(b)
#define INF 0x7fffffff

int h,n,m;
int a[MAXH][MAXN][MAXN];
int sum[MAXH][MAXN][MAXN];//sum[k][i][j]前 k 层的前 i 行的第 j 列的和
int f[MAXN];

void debug()
{
    int k,i,j;
    for(k=1;k<=h;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                printf("%d ",sum[k][i][j]);
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //freopen("rqn93.in","r",stdin);
    //freopen("rqn93.out","w",stdout);
    scanf("%d%d%d",&h,&n,&m);
    int k,i,j;
    for(k=1;k<=h;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[k][i][j]);
                sum[k][i][j]=sum[k][i-1][j]+a[k][i][j];
            }
    //debug();
    for(k=1;k<=h;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                sum[k][i][j]+=sum[k-1][i][j];
    //debug();
    int kk,ii,cc;
    int maxx=-INF;
    for(k=1;k<=h;k++)
        for(kk=k;kk<=h;kk++)
            for(i=1;i<=n;i++)
                for(ii=i;ii<=n;ii++)
                {
                    f[0]=0;
                    for(j=1;j<=m;j++)
                    {
                        //printf("k=%d;kk=%d;i=%d;ii=%d;j=%d;",k,kk,i,ii,j);
                        cc=sum[kk][ii][j]-sum[kk][i-1][j]-(sum[k-1][ii][j]-sum[k-1][i-1][j]);
                        f[j]=max(f[j-1]+cc,cc);
                        maxx>?=f[j];
                        //printf("maxx=%d\n",maxx);
                    }
                }
    printf("%d",maxx);
    return 0;
}

