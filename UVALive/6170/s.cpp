#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int M=100005;
long long x,y;
long long a,b,c;
long long solve(long long a,long long  b,long long &x,long long  &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long g=solve(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-(a/b)*y;
    return g;
}
int main()
{
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        if(!a && !b && !c)break;
        long long g=solve(a,b,x,y);
        if(c % g)
        {
            printf("Unquibable!\n");
            continue;
        }
        x=((x%(b/g)*((c/g)%(b/g)))%(b/g)+(b/g))%(b/g);
        y=(c-a*x)/b;
        if(y<0)
        {
           printf("Unquibable!\n");
           continue;
        }
        if(x==1)
        printf("1 foom and ");
        else
        printf("%lld fooms and ",x);
        if(y==1)
        printf("1 foob for a twob!\n");
        else
        printf("%lld foobs for a twob!\n",y);
    }
    return 0;
}

