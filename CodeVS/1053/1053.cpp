#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[110];

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
    gets(s);
    sort(s,s+strlen(s));
    int i,last=0,c=1,maxn=0,minn=999;
    for(i=1;i<=strlen(s);i++)
    {
        if(s[i]==s[last])c++;
        else{
            if(maxn<c) maxn=c;
            if(minn>c) minn=c;
            last=i;
            c=1;
        }
    }
    int ans=maxn-minn;
    if(is_prime(ans)) printf("Lucky Word\n%d",ans);
    else printf("No Answer\n0");
    return 0;
}
