#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

int n,a[100010],c[100010];

int main()
{
    //freopen("rqn167.in","r",stdin);
    //freopen("rqn167.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)continue;
        int l=1,r=len,m;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(c[m]>a[i])l=m+1;
            else r=m-1;
        }
        len=max(len,l);
        c[l]=a[i];
    }
    printf("%d",len);
    return 0;
}

