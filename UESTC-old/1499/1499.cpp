#include<cstdio>
#include<cstring>
const int N=1500+10;
const int inf=0x3f3f3f3f;
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int father[N],son[N][30],num[N];
int deg[N],root;
int f[N][2];

void read()
{
	for(int i=1;i<=n;i++)
	{
		int x,a;
		scanf("%d:(%d)",&x,&a);
		num[x]=a;
		for(int j=1;j<=num[x];j++)
		{
			int y; scanf("%d",&y);
			father[y]=x;
			son[x][j]=y;deg[y]++;
		}
	}
}

int dfs(int x,int sta)
{
	if(f[x][sta]!=-1) return f[x][sta];
	if(num[x]==0) return f[x][sta]=sta;
	f[x][sta]=sta;
	for(int i=1;i<=num[x];i++)
	{
		if(sta) f[x][sta]+=min(dfs(son[x][i],0),dfs(son[x][i],1));
		else f[x][sta]+=dfs(son[x][i],1);
	}
	return f[x][sta];
}

void work()
{
	root=-1;
	for(int i=0;i<n;i++) 
		if(!deg[i]) {root=i;break;}
	printf("%d\n",min(dfs(root,0),dfs(root,1)));
}

int main()
{
	freopen("1499.in","r",stdin);
	freopen("1499.out","w",stdout);
	while(scanf("%d",&n)==1)
	{
		memset(father,0,sizeof(father));
		memset(son,0,sizeof(son));
		memset(num,0,sizeof(num));
		memset(deg,0,sizeof(deg));
		memset(f,-1,sizeof(f));
		read();
		work();
	}
	return 0;
}
