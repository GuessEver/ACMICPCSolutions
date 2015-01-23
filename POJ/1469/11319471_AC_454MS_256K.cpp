#include<cstdio>
#include<cstring>
const int N=300+10;
int n,m;
bool map[N][N];
bool h[N];
int pre[N];

bool search(int x)
{
	for(int i=1;i<=m;i++)
	if(map[x][i]&&!h[i])
	{
		h[i]=true;
		if(pre[i]==-1||search(pre[i]))
		{
			pre[i]=x;
			return true;
		}
	}
	return false;
}

void work()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int cnt;scanf("%d",&cnt);
		while(cnt--)
		{
			int x;scanf("%d",&x);
			map[i][x]=true;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		memset(h,0,sizeof(h));
		if(search(i)) res++;
	}
	if(res==n) puts("YES");
	else puts("NO");
}

int main()
{
	//freopen("poj1469.in","r",stdin);
	//freopen("poj1469.out","w",stdout);
	int g;scanf("%d",&g);
	while(g--)
	{
		memset(map,0,sizeof(map));
		memset(pre,-1,sizeof(pre));
		work();
	}
	//while(1);
	return 0;
}
