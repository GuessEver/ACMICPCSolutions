#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int n,a[2010],sum[2010];
int f[2010][2010];
bool vis[2010][2010];

int getmax(int l,int r)
{
    if(r-l+1<2) return 0;
    if(r-l+1==2) return a[l]+a[r];
    if(vis[l][r]) return f[l][r];
    vis[l][r]=true;
    for(int k=l;k<r;k++)
        f[l][r]=min(f[l][r],getmax(l,k)+getmax(k+1,r)+sum[r]-sum[l-1]);
    return f[l][r];
}

int main()
{
    freopen("1055.in","r",stdin);
    freopen("1055.out","w",stdout);
    scanf("%d",&n);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i+n]=a[i];}
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=getmax(1,n);
    printf("%d",ans);
    return 0;
}

