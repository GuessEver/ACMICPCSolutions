#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define sqr(_) ((_)*(_))
const int N=1000+10;
const double pi=4.0*atan(1.0);
int n,L;
struct node{int x,y;}a[N];
int st[N],top;
int P[N],Cnt;

void read()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
}

bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cross(int i,int j,int k)
{
	int x1=a[j].x-a[i].x, y1=a[j].y-a[i].y;
	int x2=a[k].x-a[j].x, y2=a[k].y-a[j].y;
	return (x1*y2>=x2*y1);
}

double dis(int i,int j)
{
	return sqrt((double)sqr(a[i].x-a[j].x)+(double)sqr(a[i].y-a[j].y));
}

void work()
{
	sort(a+1,a+1+n,cmp);
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
	double res=0.0;
	for(int i=1;i<Cnt;i++) res+=dis(P[i],P[i-1]);
	res+=pi*2.0*(double)L;
	printf("%d\n",(int)(res+0.5));
}

int main()
{
	read();
	work();
	return 0;
}