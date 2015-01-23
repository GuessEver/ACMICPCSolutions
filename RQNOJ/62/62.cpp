#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110

int n,a[MAXN],sum;

int main()
{
    //freopen("noipg1.in","r",stdin);
    //freopen("noipg1.out","w",stdout);
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++) {scanf("%d",&a[i]);sum+=a[i];}
    sum/=n;
    for(i=1;i<=n;i++) a[i]-=sum;
    int step=0;
    for(i=1;i<n;i++)//最后一张不用管  因为到最后一张时必定成功
    {
        if(a[i]==0)continue;
        step++;
        a[i+1]+=a[i];
        a[i]=0;
    }
    printf("%d",step);
    return 0;
}

