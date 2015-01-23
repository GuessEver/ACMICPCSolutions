#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define sqr(_) ((_)*(_))
const int N=50000+10;

int n;
struct node{int x,y;}a[N];
int st[N],top;
int P[N],Cnt;

inline int cross(int i,int j,int k)
{
	int x1=a[j].x-a[i].x, y1=a[j].y-a[i].y;
	int x2=a[k].x-a[i].x, y2=a[k].y-a[i].y;
	return x1*y2-x2*y1;
}

bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

void graham()
{
	sort(a+1,a+1+n,cmp);
	st[top=1]=1;
	for(int i=2;i<=n;i++)
	{
		while(top>1 && cross(st[top],st[top-1],i)>=0) top--;
		st[++top]=i;
	}
	for(int i=1;i<=top;i++) P[Cnt++]=st[i];
	st[top=1]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(top>1 && cross(st[top],st[top-1],i)>=0) top--;
		st[++top]=i;
	}
	for(int i=2;i<=top;i++) P[Cnt++]=st[i];
	for(int i=0;i<Cnt;i++) printf("%d %d\n",a[P[i]].x,a[P[i]].y);
}

inline int dis(int i,int j)
{ return sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y); }

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	graham();P[Cnt]=P[0];
	int j=1,res=0;
	for(int i=0;i<Cnt;i++)
	{
		while(cross(P[i],P[i+1],P[j])<cross(P[i],P[i+1],P[j+1]))
		{
			j++;
			if(j>=Cnt) j=0;
		}
		res=max(res,dis(P[i],P[j]));
	}
	printf("%d\n",res);
	return 0;
}