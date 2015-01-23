#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define copymap(a,b) for(int _i=0;_i<n;_i++)for(int _j=0;_j<n;_j++)a[_i][_j]=b[_i][_j];

const int MAXN=30;
const int dx[]={0,0,1,-1,0};
const int dy[]={1,-1,0,0,0};

int n;
int map[MAXN][MAXN];
int oldmap[MAXN][MAXN];
int firstmap[MAXN][MAXN];
int a[MAXN];
int ans=0x7fffffff;

void read()
{
	n=4;
	char s[30];
	for(int i=0;i<n;i++)
	{
		scanf("%s\n",s);
		for(int j=0;j<n;j++)
		    map[i][j]=((s[j]=='b')?1:0);
	}
	copymap(firstmap,map);
}

void change(int x,int y)
{
	for(int k=0;k<5;k++)
	{
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(nx>=n||nx<0) continue;
		if(ny>=n||ny<0) continue;
		map[nx][ny]=1-map[nx][ny];
	}
}

void turn(int sum,int k)
{
	for(int i=1;i<n;i++)
		for(int j=0;j<n;j++)
		    if(map[i-1][j]!=k)
		    {
				change(i,j);
				sum++;
			}
	bool flag=true;
	for(int j=0;j<n;j++)
	    if(map[n-1][j]!=k) {flag=false;break;}
	if(flag) ans=min(ans,sum);
}

void dfs(int x,int sum)
{
	if(x>=n)//边界
	{
		for(int i=0;i<n;i++)
			if(a[i]) change(0,i);
		copymap(oldmap,map);
		turn(sum,1);
		copymap(map,oldmap);
		turn(sum,0);
		copymap(map,firstmap);
		return;
	}
	a[x]=1;
	dfs(x+1,sum+1);
	a[x]=0;
	dfs(x+1,sum);
}

void work()
{
	dfs(0,0);
	if(ans==0x7fffffff) printf("Impossible");
	else printf("%d\n",ans);
}

int main()
{
	read();
	work();
	return 0;
} 				    
