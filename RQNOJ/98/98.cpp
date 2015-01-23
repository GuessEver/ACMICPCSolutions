#include<cstdio>
#define MAXN 2010
#define MAXM 510
#define INF 0x7fffffff
#define max(a,b) (a)>(b)?(a):(b)

int n,m,num[MAXN],w[MAXN],v[MAXN];
int f[MAXM];

int main()
{
    //freopen("rqn98.in","r",stdin);
    //freopen("rqn98.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&num[i],&w[i],&v[i]);
    int maxx=-INF;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            for(int k=1;k<=num[i];k++)
            {
                //printf("i=%d  j=%d  k=%d  f[j]=%d\n",i,j,k,f[j]);
                if(k*w[i]>j)break;
                if(j>=w[i])f[j]=max(f[j],f[j-w[i]*k]+v[i]*k);
                maxx=max(maxx,f[j]);
            }
    printf("%d",maxx);
    return 0;
}

