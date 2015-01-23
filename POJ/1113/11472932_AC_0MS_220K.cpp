#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1000+10;
const double pi=4.0*atan(1.0);
#define sqr(_) ((_)*(_))

int n,L;
struct node{int x,y;}a[N];
int P[N];
int st[N],top,Cnt;

bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

void read()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
}

double dis(int i,int j)
{
	return sqrt((double)sqr(a[i].x-a[j].x)+(double)sqr(a[i].y-a[j].y));
}

bool cross(int i,int j,int k)
{
	int x1=a[j].x-a[i].x, y1=a[j].y-a[i].y;
	int x2=a[k].x-a[j].x, y2=a[k].y-a[j].y;
	return (x1*y2-x2*y1>=0);
}

void graham()
{
	st[top=1]=1;
	for(int i=2;i<=n;i++)
	{
		while(top>1 && cross(st[top],st[top-1],i)) top--;
		st[++top]=i;
	}
	for(int i=1;i<=top;i++) P[Cnt++]=st[i];
	st[top=1]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(top>1 && cross(st[top],st[top-1],i)) top--;
		st[++top]=i;
	}
	for(int i=2;i<=top;i++) P[Cnt++]=st[i];
}

void work()
{
	graham();
	//for(int i=0;i<Cnt;i++)
		//printf("%d : Point %d : ( %d , %d )\n",i,P[i],a[P[i]].x,a[P[i]].y);
	double res=0;
	for(int i=1;i<Cnt;i++) res+=dis(P[i],P[i-1]);
	res+=2.0*pi*(double)L;
	printf("%.0lf\n",res);
}

int main()
{
	read();
	work();
	return 0;
}