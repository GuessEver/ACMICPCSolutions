#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAXN 200010

typedef long long LL;
LL s;
int n,m,w[MAXN],v[MAXN],l[MAXN],r[MAXN],maxw;
LL num[MAXN],sum[MAXN];

LL getyi(int l,int r)
{ return (LL)(num[r]-num[l-1])*(sum[r]-sum[l-1]); }

void predoing(int mid)
{
    for(int i=1;i<=n;i++)
    {
        num[i]=num[i-1];
        sum[i]=sum[i-1];
        if(w[i]>=mid)
        {
            num[i]++;
            sum[i]+=v[i];
        }
    }
}

LL gety(int mid)
{
    LL y=0,yi;
    predoing(mid);
    for(int i=1;i<=m;i++)
    {
        yi=getyi(l[i],r[i]);
        y+=yi;
    }
    return y;
}

int main()
{
    scanf("%d%d",&n,&m);cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
        if(maxw<w[i]) maxw=w[i];
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d",&l[i],&r[i]);
    int left=0,right=maxw,mid,p;
    while(left+1<right)//区间大小为2的时候易进入死循环  停下最后特判
    {                  //二分找到最后一个大于s的检验值，最后比较下一个检验值（即第一个小于s的的），哪个更优
        mid=left+(right-left)/2;
        LL cc=gety(mid);
        if(cc>=s)left=mid;
        else right=mid-1;
    }
    LL ans=min(abs(gety(right)-s),abs(gety(left)-s));//特判
    cout<<min(ans,abs(gety(left+1)-s));//更优
    return 0;
}
