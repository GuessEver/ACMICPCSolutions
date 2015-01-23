/*
ID: jiangzh15
TASK: milk
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAXN 5010

int n,m;
struct node{int p,k;}a[MAXN];

bool cmp(node a,node b){ return a.p<b.p; }

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++)
        scanf("%d%d",&a[i].p,&a[i].k);
    sort(a+1,a+1+m,cmp);
    int j,sump=0,sumn=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=a[i].k;j++)
        {
            sumn++;
            sump+=a[i].p;
            if(sumn==n){printf("%d\n",sump);exit(0);}
        }
    printf("%d\n",sump);
    return 0;
}
