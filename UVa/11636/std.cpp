/*
uva 11636
PROB:  Hello World!
*/
#include<stdio.h>
#include<string.h>
int n;
int main()
{
        freopen("11636.in","r",stdin);
        freopen("std.out","w",stdout);
        int ncase=0;
        while(1)
        {
        ncase++;
        scanf("%d",&n);
        int ans=0;
        if(n<=0)
            break;
        int tmp=1;    
        while(tmp*2<n)
        {
            ans++;
            tmp*=2;
        }
        if(tmp!=n)
            ans++;
                printf("Case %d: %d\n",ncase,ans);
        }
        return 0;
}
