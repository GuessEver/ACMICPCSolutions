//TLE 90
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int a,aa,b,bb,ans;

int gcd(int a,int b) //{ return b==0 ? a : gcd(b,a%b); }
{
    int r;
    for(;;)
    {
        if(b==0)return a;
        r=a%b;a=b;b=r;
    }
}
bool check(int x)
{
    if(gcd(a,x)==aa && b/gcd(b,x)*x==bb)return true;
    return false;
}

void work()
{
    scanf("%d%d%d%d",&a,&aa,&b,&bb);
    ans=0;
    for(int i=1;i<=sqrt(bb);i++)
        if(bb%i==0)
        {
            if(check(i)) ans++;
            if(i!=bb/i && check(bb/i)) ans++;
        }
    printf("%d\n",ans);
}

int main()
{
    //freopen("son.in","r",stdin);
    //freopen("son.out","w",stdout);
    int groups;
    scanf("%d",&groups);
    for(int i=1;i<=groups;i++)
        work();
    return 0;
}

