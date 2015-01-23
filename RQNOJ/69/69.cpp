#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 100

const int dx[]={0,-1,-2,-2,-1,+1,+2,+2,+1};
const int dy[]={0,-2,-1,+1,+2,-2,-1,+1,+2};
int n,m,x,y;
long long f[MAXN][MAXN];
bool map[MAXN][MAXN];

int main()
{
    //freopen("rqn69.in","r",stdin);
    //freopen("rqn69.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&x,&y);
    map[x][y]=true;
    for(int k=1;k<=8;k++)
        if(x+dx[k]>=0 && x+dx[k]<=n && y+dy[k]>=0 && y+dy[k]<=m)
            map[x+dx[k]][y+dy[k]]=true;
    f[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(!map[i][j])
            {
                if(i>0)f[i][j]+=f[i-1][j];
                if(j>0)f[i][j]+=f[i][j-1];
            }
    cout<<f[n][m];
    return 0;
}

