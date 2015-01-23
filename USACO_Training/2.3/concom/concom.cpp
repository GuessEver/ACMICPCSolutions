/*
TASK: concom
LANG: C++
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=100+10;
const int M=5000+10;

int n,m;
struct Link{int y,z;Link *next;}*head[N];
int hash[N][N];
int vis[N][N];

void inLink(int x,int y,int z)
{
	Link *p=new Link;
	p->y=y; p->z=z;
	p->next=head[x];
	head[x]=p;
}

void read()
{
	scanf("%d",&m);
	while(m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		inLink(x,y,z);
		n=std::max(n,std::max(x,y));
	}
}

void calc(int d,int x)
{
	if(vis[d][x]) return;
	vis[d][x]=1;
	for(Link *p=head[x];p;p=p->next)
	{
		hash[d][p->y]+=p->z;
		if(hash[d][p->y] > 50) calc(d,p->y);
	}
}

void solve()
{
	memset(vis,0,sizeof(vis));
	for(int x=1;x<=n;x++)
	{
		calc(x,x);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			if(i!=j && hash[i][j]>50)
				printf("%d %d\n",i,j);
}

int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	read();
	solve();
	return 0;
}

