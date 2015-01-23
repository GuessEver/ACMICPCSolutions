#include<cstdio>

int main()
{
    long long n;
    scanf("%lld",&n);
    long long res=0;
    for(long long i=1;i<=n;i++) res+=i;
    printf("%lld\n",res);
    return 0;
}
