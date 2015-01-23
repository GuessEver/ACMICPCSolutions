#include<cstdio>
#include<cstring>
#define MAXN 260
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int n,m,dis[MAXN][MAXN];
bool map[MAXN][MAXN];
bool h[MAXN][MAXN];
int ans=0x3f3f3f3f;

void dfs(int x,bool flag,int sum,int tar)//x 当前点   flag 是否为第一个点   sum 目前总和   tar 目标点
{
    if(sum>ans) return;
    if(flag && x==tar) {ans=min(ans,sum);return;}
    
    for(int i=1;i<=n;i++)
        if(map[x][i] && !h[x][i])
        {
            h[x][i]=h[i][x]=true;
            dfs(i,true,sum+dis[x][i],tar);
            h[x][i]=h[i][x]=false;
        }
    
}

int main()
{
    //freopen("heart.in","r",stdin);
    //freopen("heart.out","w",stdout);
    scanf("%d%d",&n,&m);
    memset(dis,0x3f,sizeof(dis));
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        map[x][y]=map[y][x]=true;
        dis[x][y]=dis[y][x]=z;
    }
    
    for(int i=1;i<=n;i++)
        dfs(i,false,0,i);
    
    if(ans==0x3f3f3f3f) printf("He will never come back.");
    else printf("%d",ans);
    return 0;
}

