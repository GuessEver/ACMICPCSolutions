#include<cstdio>

int n,m,a[510];
bool f[45010];

int main()
{
    //freopen("ty1028.in","r",stdin);
    //freopen("ty1028.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0]=true;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=a[i];j--)
            if(f[j-a[i]]) f[j]=true;
    for(int i=m;i>=0;i--)
        if(f[i]){ printf("%d",i); break; }
    return 0;
}

