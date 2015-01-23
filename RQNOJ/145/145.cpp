#include<cstdio>
#define MAXN 10010
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define INF 0x7fffffff

int n,a[MAXN],sum[MAXN],f[MAXN];

int main()
{
    //freopen("rqn145.in","r",stdin);
    //freopen("rqn145.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);sum[i]=sum[i-1]+a[i];}
    int maxx=-INF,l=1,r=1;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(sum[j]-sum[i-1]>maxx)
            {
                maxx=sum[j]-sum[i-1];
                l=i;r=j;
            }
    printf("%d %d\n%d",l,r,maxx);
    return 0;
}

