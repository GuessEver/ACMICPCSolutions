#include<stdio.h>
long s[101];
int main()
{
    long n,m,i,j,a,b,ta,tb;
    scanf("%ld%ld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%ld%ld",&ta,&tb);
        for(j=1;j<=n;j++)
        {
            scanf("%ld%ld",&a,&b);
            if(a>b&&ta>tb)s[j]+=2;
            if(a<b&&ta<tb)s[j]+=2;
            if(a==b&&ta==tb)s[j]+=2;
            if(ta-tb==a-b)s[j]+=3;
            if(ta==a)s[j]+=1;
            if(tb==b)s[j]+=1;
        }

    }
    for(i=1;i<=n;i++)
        printf("%ld ",s[i]);

    return 0;
}

