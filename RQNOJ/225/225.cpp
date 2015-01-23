#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int n,m;
struct node{int x,y;}a[MAXN];
int f[MAXN][MAXN];//f[i][j]表示前 i 个 留下 j 个 ，并且第 i 个必须留的最优值

bool cmp(node a,node b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    //freopen("book.in","r",stdin);
    //freopen("book.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);

    memset(f,0x07,sizeof(f));
    for(int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
    for(int j=1;j<=n-m;j++)
        for(int i=1;i<=n;i++)
            for(int k=1;k<i;k++)
                f[i][j]=min(f[i][j],f[k][j-1]+abs(a[k].y-a[i].y));
    int ans=f[n][n-m];
    for(int i=1;i<=n;i++) ans=min(ans,f[i][n-m]);
    printf("%d",ans);
    return 0;
}

