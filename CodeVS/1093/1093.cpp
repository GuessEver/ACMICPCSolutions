#include<cstdio>
#include<algorithm>
using std::max;
const int N=20+10;
const int K=1000+10;

int n,m,t;
int map[N][N];
int res=0;
int maxx,a,b;
void findmax()
{
	maxx=0;a=0;b=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]>maxx)
			{
				maxx=map[i][j];
				a=i;b=j;
			}
}

int dis(int x,int y,int a,int b)
{ return abs(x-a)+abs(y-b); }

void printmap()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%d ",map[i][j]);
		puts("");
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	bool flag=true;
	int x=0,y=0;
	findmax();
	y=b;
	int sum=0;
	while(flag)
	{
		findmax();
		if(dis(x,y,a,b)+1>t || map[a][b]==0) flag=false;
		if(flag)
		{
			sum+=map[a][b];
			t=t-dis(x,y,a,b)-1;
			map[a][b]=0;
			x=a;y=b;
		}
		if(dis(0,y,x,y)<=t) res=max(res,sum);
		//printf("t=%d a=%d b=%d x=%d y=%d sum=%d\n",t,a,b,x,y,sum);
		//getchar();
	}
	printf("%d",res);
	//while(1);
	return 0;
}
