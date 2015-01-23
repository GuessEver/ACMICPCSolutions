#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int a[2010],b[2010];

bool cmp(int a,int b){ return a>b; }

int main()
{
    //freopen("rqn96.in","r",stdin);
    //freopen("rqn96.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    sort(b+1,b+1+m,cmp);
    //sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
    //for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
    int sum=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[j]>0 && a[i]>b[j]) {b[j]=-1;sum++;break;}
    printf("%d",m-sum);
    return 0;
}

