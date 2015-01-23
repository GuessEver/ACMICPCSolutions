#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

int n,a[50];
int c[50],len=0;

int main()
{
    //freopen("ty1209.in","r",stdin);
    //freopen("ty1209.out","w",stdout);
    scanf("%d",&a[++n]);
    while(scanf(",%d",&a[++n]));n--;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=len,m;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(c[m]>=a[i]) l=m+1;
            else r=m-1;
        }
        c[l]=a[i];
        len=max(len,l);
    }
    printf("%d,",len);
    len=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=len,m;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(c[m]<a[i]) l=m+1;
            else r=m-1;
        }
        c[l]=a[i];
        len=max(len,l);
    }
    printf("%d",len-1);
    return 0;
}

