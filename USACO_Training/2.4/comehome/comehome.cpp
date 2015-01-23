/*
LANG: C++
TASK: comehome
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#define min(a,b) ((a)<(b)?(a):(b))
const int inf=0x3f3f3f3f;
const int N=200;
int n,m;
int map[N][N];
bool peo[N];
int dist[N];
bool h[N];

inline bool big(char x)
{
	return toupper(x)==x;
}

int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	scanf("%d\n",&m);
	memset(map,0x3f,sizeof(map));
	for(int i=1;i<=m;i++)
	{
		char x,y;int z;
		scanf("%c %c %d\n",&x,&y,&z);
		if(big(x)) peo[x]=true;
		map[y][x]=map[x][y]=min(map[x][y],z);
	}
	n='z';
	memset(dist,0x3f,sizeof(dist));
	dist['Z']=0;
	for(int i=1;i<=n;i++)
	{
		int k=-1;
		for(int j=1;j<=n;j++)
			if(!h[j] && (k==-1||dist[j]<dist[k])) k=j;
		h[k]=true;
		for(int j=1;j<=n;j++)
			if(!h[j] && dist[j]>dist[k]+map[k][j])
				dist[j]=dist[k]+map[k][j];
	}
	int res=-1;
	for(int i='A';i<='z';i++)
	{
		if(dist[i]==inf) continue;
		if(i=='Z') continue;
		if(!big(i)) continue;
		if(res==-1 || dist[i]<dist[res]) res=i;
	}
	printf("%c %d\n",res,dist[res]);
	return 0;
}
