#include<cstdio>
#include<algorithm>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
const int N=100000+10;
int n,m;
struct EG{int x,y,z;}edge[N*2];
int L;
LL res;
int f[N];

void addedge(int x,int y,int z)
{
	edge[L].x=x;
	edge[L].y=y;
	edge[L].z=z;
	L++;
}

int getroot(int x){return (f[x]==x)?x:(f[x]=getroot(f[x]));}
void merge(int x,int y){f[getroot(x)]=getroot(y);}

bool cmp(EG a,EG b){ return a.z<b.z; }

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	sort(edge,edge+L,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<L;i++)
	{
		if(getroot(edge[i].x)==getroot(edge[i].y)) continue;
		res+=edge[i].z;
		merge(edge[i].x,edge[i].y);
	}
	printf("%lld\n",res);
	return 0;
}
