#include<cstdio>
#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
const int N=20+10;
const int NN=N*N;
const int inf=0x3f3f3f3f;
int n,m,d,lizard_tot;
int height[N][N],lizard[N][N];
int g[NN][NN],S,T;
int v[NN],h[NN];

inline int IN(int x,int y){return (x*m+y)*2+1;}
inline int OU(int x,int y){return (x*m+y)*2+2;}

void read()
{
	scanf("%d%d%d",&n,&m,&d);
	char s[100];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++) 
			height[i][j]=s[j]-'0';
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
		{
			lizard[i][j]=(s[j]=='L');
			if(lizard[i][j]) lizard_tot++;
		}
	}
}

inline void inlink(int x,int y,int flow) { g[x][y]=flow; }
inline int dis(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void build_map()
{
	S=OU(n-1,m-1)+1; T=OU(n-1,m-1)+2;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(lizard[i][j]) inlink(S,IN(i,j),1);
			if(height[i][j])
			{
				inlink(IN(i,j),OU(i,j),height[i][j]);
				if(i<d||i>=n-d||j<d||j>=m-d)
					inlink(OU(i,j),T,inf);
				for(int x=0;x<n;x++)
					for(int y=0;y<m;y++)
					{
						if(i==x && j==y) continue;
						if(!height[x][y]) continue;
						if(dis(i,j,x,y)<=d*d)
							inlink(OU(i,j),IN(x,y),inf);
					}
			}
		}
}

int sap(int x,int flow)
{
	if(x==T) return flow;
	int res=0;
	for(int i=0;i<=T;i++)
		if(g[x][i] && h[x]==h[i]+1)
		{
			int t=sap(i,min(g[x][i],flow-res));
			g[x][i]-=t; g[i][x]+=t;
			if((res+=t)==flow) return res;
			if(h[S]>=T) return res;
		}
	if(!(--v[h[x]])) h[S]=T;
	++v[++h[x]];
	return res;
}

void work()
{
	build_map();
	int res=0;
	v[S]=T;
	while(h[S]<T) res+=sap(S,inf);
	printf("%d\n",lizard_tot-res);
}

int main()
{
	freopen("lizard.in","r",stdin);
	freopen("lizard.out","w",stdout);
	read();
	work();
	return 0;
}
