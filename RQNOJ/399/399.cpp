#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

string s;

bool is_prime(int x)
{
    if(x<2)return false;
    if(x==2)return true;
    for(int i=2;i<x;i++)
        if(x%i==0)return false;
    return true;
}

int main()
{
    //freopen("rq399.in","r",stdin);
    //freopen("rq399.out","w",stdout);
    getline(cin,s);
    sort(s.begin(),s.end());
    int maxx=0,minx=0x7fffffff,sum=0;
    char ch=s[0];
    s+='~';//便于处理
    for(int i=0;i<s.length();i++)
    {
        if(ch==s[i]) sum++;
        else {
            maxx=max(sum,maxx);
            minx=min(sum,minx);
            sum=1;ch=s[i];
        }
    }
    int ans=maxx-minx;
    if(is_prime(ans)) printf("Lucky Word\n%d",ans);
    else printf("No Answer\n0");
    return 0;
}

