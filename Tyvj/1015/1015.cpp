#include<cstdio>
#include<iostream>
using namespace std;

typedef unsigned long long LL;
int n;
LL f[100];

int main()
{
    //freopen("Q1015.in","r",stdin);
    //freopen("Q1015.out","w",stdout);
    scanf("%d",&n);
    f[0]=1;f[1]=2;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n];
    return 0;
}

