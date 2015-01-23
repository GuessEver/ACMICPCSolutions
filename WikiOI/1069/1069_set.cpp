#include<cstdio>
#include<algorithm>
using std::sort;
const int N=20000+10;
const int M=100000+10;
int n,m;
int f[N];
int r[N];
struct node{int a,b,c;}e[M];

int getroot(int x) { return f[x]==x ? x : f[x]=getroot(f[x]); }
inline void merge(int x,int y) { f[getroot(x)]=getroot(y); } 

bool cmp(node a,node b) { return a.c>b.c; }

int main()
{
	freopen("1069.in","r",stdin);
	freopen("1069.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a=e[i].a, b=e[i].b, c=e[i].c;
		if(getroot(a)==getroot(b))
		{
			printf("%d\n",c);
			return 0;
		}
		if(r[a]==0) r[a]=b;
		if(r[b]==0) r[b]=a;
		merge(a,r[b]);
		merge(b,r[a]);
	}
	printf("0\n");
	return 0;
}
