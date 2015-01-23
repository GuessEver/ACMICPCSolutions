#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=201;
const int MAXT=40004;
struct xy{
	int x,y,t,v,dis;
} point[MAXN][MAXN];
xy * pp[MAXN][MAXN];
int n,t,len;
int llen[MAXN];
bool cmp(const struct xy &a,const struct xy &b)
{
	return a.dis<b.dis;
}
int dp[MAXT];
int main()
{
	//freopen("in.txt","r",stdin);
	int cas=1;
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		
		memset(point,0,sizeof(point));
		memset(dp,0,sizeof(dp));
		struct xy tmp;
		len=0;llen[len]=0;
		scanf("%d%d%d%d",&tmp.x,&tmp.y,&tmp.t,&tmp.v);
		tmp.dis=tmp.x*tmp.x+tmp.y*tmp.y;
		point[len][llen[len]++]=tmp;
		for(int i=1;i<n;++i)
		{
			scanf("%d%d%d%d",&tmp.x,&tmp.y,&tmp.t,&tmp.v);
			tmp.dis=tmp.x*tmp.x+tmp.y*tmp.y;
			bool coline=false;
			for(int j=0;j<=len;++j)
				if(point[j][0].x*tmp.y==tmp.x*point[j][0].y)
				{
					point[j][llen[j]++]=tmp;
					coline=true;
					break;
				}
			if(!coline)
			{
				++len;
				llen[len]=1;
				point[len][0]=tmp;
			}
		}

		
		for(int i=0;i<=len;++i)
			sort(point[i],point[i]+llen[i],cmp);
		for(int i=0;i<=len;++i)
			for(int j=1;j<llen[i];++j)
			{
				point[i][j].v+=point[i][j-1].v;
				point[i][j].t+=point[i][j-1].t;
			}
		/*for(int i=0;i<=len;++i)
		{
			printf("%d",llen[i]);
			for(int j=0;j<llen[i];++j)
				printf("-->x:%d y:%d v:%d  t:%d",point[i][j].x,point[i][j].y,point[i][j].v,point[i][j].t);
			printf("\n");
		}*/
		for(int i=0;i<=len;++i)
			for(int tt=t;tt>=0;--tt)
				for(int j=0;j<llen[i];++j)
				if(tt-point[i][j].t>=0)
				dp[tt]=max(dp[tt],dp[tt-point[i][j].t]+point[i][j].v);

		printf("Case %d: %d\n",cas++,dp[t]);
	}
}
