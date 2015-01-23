#include<cstdio>
#include<algorithm>
#define MAXN 110

int n,a[MAXN*2],f[MAXN*2][MAXN*2];

int getsum(int l,int r)
{
    if(r-l+1<2)return 0;
    if(r-l+1==2) return (a[l]*a[r]*a[r+1]);
    if(f[l][r]!=0)return f[l][r];
    for(int j=l+1;j<=r;j++)
        f[l][r]=std::max(f[l][r],getsum(l,j-1)+getsum(j,r)+a[l]*a[j]*a[r+1]);
    return f[l][r]; 
}

int main()
{
    //freopen("energy.in","r",stdin);
    //freopen("energy.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    int best=0;
    for(int i=1;i<=n;i++)
        best=std::max(best,getsum(i,i+n-1));
    printf("%d",best);
}

