/*
C++ Code
http://oijzh.cnblogs.com
*/
#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;
#define MAXN 1010

int n,m,ans;
list<int> q;

bool find(int x)
{
    list<int>::iterator pos=find(q.begin(),q.end(),x);
    if(pos==q.end())return false;
    else return true;
}
void inq(int x)
{
    if(q.size()>=m) q.pop_front();
    q.push_back(x);
}

int main()
{
    //freopen("translate.in","r",stdin);
    //freopen("translate.out","w",stdout);
    scanf("%d%d",&m,&n);
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(!find(x)) inq(x);
        else ans++;//ans记录能在内存中找的次数
    }
    printf("%d",n-ans);
    return 0;
}

