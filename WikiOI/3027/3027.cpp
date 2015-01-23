#include<cstdio>
#include<algorithm>
const int N=1000+10;
int n;
struct EG{int x,y,z;}edge[N];
int f[N];

bool cmp(EG a,EG b)
{
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	freopen("3027.in","r",stdin);
	freopen("3027.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
	std::sort(edge+1,edge+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i]=edge[i].z;
		for(int j=1;j<i;j++)
			if(edge[i].x >= edge[j].y)
			{
				f[i]=std::max(f[i],f[j]+edge[i].z);
			}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=std::max(res,f[i]);
	printf("%d\n",res);
	return 0;
}
