#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500+10;
const int M=5000+10;
const int inf=0x3f3f3f3f;

int n,m,S,T;
struct EG{int x,y,z;}edge[M*2];
int L;
int f[N];
struct node{int a,b;double z;}ans[N*N];

bool cmp(EG a,EG b) { return a.z>b.z; }
bool cmp2(node a,node b) { return a.z<b.z; }

int getroot(int x) { return f[x]==x ? x : f[x]=getroot(f[x]); }
inline void merge(int x,int y) { f[getroot(x)]=getroot(y); }

int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }

void printans(int a,int b)
{
	int tmp=gcd(a,b);
	a/=tmp; b/=tmp;
	if(b==1) printf("%d\n",a);
	else printf("%d/%d\n",a,b);
}

int work(int maxit)
{
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=maxit;i<L;i++)
	{
		int x=edge[i].x;
		int y=edge[i].y;
		if(getroot(x)==getroot(y)) continue;
		merge(x,y);
		if(getroot(S)==getroot(T)) return edge[i].z;
	}
	return -1;
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[L++]=(EG){x,y,z};
	}
	scanf("%d%d",&S,&T);
	sort(edge,edge+L,cmp);
	int cnt=0;
	for(int i=0;i<L;i++)
	{
		int tmp=work(i);
		double ttt=1e10;
		if(tmp!=-1) ttt=(double)edge[i].z/tmp;
		node t=(node){edge[i].z,tmp,ttt};
		ans[cnt++]=t;
		/*if(tmp==-1) printf("IMPOSSIBLE\n");
		else printans(edge[i].z,tmp);
		printf("%.2lf\n",t.z);*/
	}
	sort(ans,ans+cnt,cmp2);
	if(ans[0].z>1e9) printf("IMPOSSIBLE\n");
	else printans(ans[0].a,ans[0].b);
	return 0;
}
