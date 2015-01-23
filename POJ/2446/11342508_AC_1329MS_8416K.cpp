#include<cstdio>
#include<cstring>
const int N=50;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,m,k;
int total;
int hash[N][N];
int map[N*N][N*N];
int h[N*N];
int pre[N*N];


void getxy(int pos,int &x,int &y)
{
	x=pos/m+1;
	y=pos%m;
	if(y==0)
	{
		y=m;
		x--;
	}
}

int getpos(int x,int y)
{
	return (x-1)*m+y;
}

void read()
{
	scanf("%d%d%d",&n,&m,&k);
	total=n*m;
	for(int i=1;i<=k;i++)
	{
		int x,y; scanf("%d%d",&y,&x);
		hash[x][y]=true;
		total--;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(!hash[i][j])
		for(int k=0;k<4;k++)
		{
			int x=i+dx[k];
			int y=j+dy[k];
			if(hash[x][y]) continue;
			if(x<1||x>n) continue;
			if(y<1||y>m) continue;
			map[getpos(i,j)][getpos(x,y)]=true;
		}
}

bool search(int x)
{
	for(int i=1;i<=n*m;i++)
	if(map[x][i]&&!h[i])
	{
		h[i]=true;
		if(pre[i]==-1||search(pre[i]))
		{
			pre[i]=x;
			//printf("%d <-> %d\n",i,x);
			return true;
		}
	}
	return false;
}

void work()
{
	memset(pre,-1,sizeof(pre));
	int res=0;
	for(int i=1;i<=n*m;i++)
	{
		memset(h,0,sizeof(h));
		if(search(i)) res++;
		//printf("res=%d\n",res);
	}
	if(res==total) puts("YES");
	else puts("NO");
}

int main()
{
	//freopen("poj2446.in","r",stdin);
	//freopen("poj2446.out","w",stdout);
	read();
	work();
	//while(1);
	return 0;
}
