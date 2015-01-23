/*
ID: jiangzh15
TASK: milk2
LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 10010

struct node{int t,r;}a[MAXN];//r=0表示左界,r=1表示右界
int n;

bool cmp(node a,node b)
{
    if(a.t==b.t)return a.r<b.r;//相同则按照先左后右的原则排序
    return a.t<b.t;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    scanf("%d",&n);
    int c=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[++c].t);a[c].r=0;
        scanf("%d",&a[++c].t);a[c].r=1;
    }
    sort(a+1,a+1+c,cmp);
    int num=0,last=0;
    int maxw=0,maxr=0;
    for(int i=1;i<=c;i++)
    {
        if(!a[i].r)num++;
        if(a[i].r)num--;
        if(num==0)
        {
            maxw=max(maxw,a[i].t-a[last+1].t);
            maxr=max(maxr,a[i+1].t-a[i].t);
            last=i;
        }
    }
    printf("%d %d\n",maxw,maxr);
    return 0;
}
