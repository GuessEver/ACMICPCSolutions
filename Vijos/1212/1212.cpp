#include<cstdio>
#include<cmath>
#include<cstring>
#define sqr(_) ((_)*(_))
const int N=1000+10;

int r,a,t;
struct node{double x,y,v;}send[N],p[N];
int g[N][N],hash[N];
int pre[N];

void read()
{
	scanf("%d%d%d",&r,&a,&t);
	for(int i=1;i<=a;i++) scanf("%lf%lf",&send[i].x,&send[i].y);
	for(int i=1;i<=r;i++) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].v);
}

inline double dis(double x,double y,double a,double b)
{
	return sqrt(sqr(x-a)+sqr(y-b));
}

void build_map()
{
	for(int i=1;i<=r;i++)
	for(int j=1;j<=a;j++)
	{
		double s=dis(p[i].x,p[i].y,send[j].x,send[j].y);
		double time=s/p[i].v;
		if(time>t) continue;
		g[i][j]=1;
	}
}

int search(int x)
{
	for(int i=1;i<=a;i++)
	if(g[x][i]&&!hash[i])
	{
		hash[i]=1;
		if(pre[i]==-1||search(pre[i]))
		{
			pre[i]=x;
			return 1;
		}
	}
	return 0;
}

void work()
{
	build_map();
	int res=0;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=r;i++)
	{
		memset(hash,0,sizeof(hash));
		if(search(i)) res++;
	}
	printf("%d\n",res);
}

int main()
{
	read();
	work();
	return 0;
}
