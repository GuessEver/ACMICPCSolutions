/*
ID: jiangzh15
TASK: numtri
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1010

int n,f[MAXN][MAXN];
int map[MAXN][MAXN];

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&map[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+map[i][j];
    int maxx=f[n][1];
    for(int i=1;i<=n;i++) maxx=max(maxx,f[n][i]);
    printf("%d\n",maxx);
    return 0;
}
