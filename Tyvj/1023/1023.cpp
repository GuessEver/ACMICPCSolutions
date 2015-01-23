#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

int n,m,d[2010];
int f[2010][600];

int main()
{
    //freopen("ty1023.in","r",stdin);
    //freopen("ty1023.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    f[1][1]=d[1];f[1][0]=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+d[i+1]);
            if(i+j<=n)f[i+j][0]=max(f[i+j][0],f[i][j]);
            if(j==0)f[i+1][0]=max(f[i+1][0],f[i][0]);
        }
    printf("%d",f[n][0]);
    return 0;
}

