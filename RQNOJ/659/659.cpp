#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 1010
#define mod 10007

int a,b,k,n,m;
long long f[MAXN][MAXN];

int main()
{
    //freopen("factor.in","r",stdin);
    //freopen("factor.out","w",stdout);
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    int i,j;
    f[1][0]=a;f[0][1]=b;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            if(i>0)f[i][j]+=f[i-1][j]*a;
            if(j>0)f[i][j]+=f[i][j-1]*b;
            f[i][j]%=mod;
        }
    cout<<f[n][m]%mod;
    return 0;
}

