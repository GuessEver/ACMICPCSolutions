/*
ID: jiangzh15
TASK: barn1
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 200
#define INF 0x7fffffff

int n,s,c,a[MAXN],f[60][MAXN];

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    scanf("%d%d%d",&n,&s,&c);
    int i;
    for(i=1;i<=c;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+c);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    for(i=1;i<=n;i++)
        for(int j=1;j<=c;j++)
        {
            if(i>0&&j>0)f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            if(j>0)f[i][j]=min(f[i][j],f[i][j-1]+a[j]-a[j-1]);
        }
    int minp=INF;
    for(i=1;i<=n;i++) minp=min(minp,f[i][c]);
    printf("%d\n",minp);
    return 0;
}
