/*
LANG: C++
TASK: maze1
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using std::queue;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m;
char tmp[500];
int cap[500][500];
struct Node{int x,y,step;};
queue<Node> Q;
int inQ[500][500];
int dist[3][500][500];

bool expand(Node node,Node &newnode,int k)
{
	int nx=node.x+dx[k];
	int ny=node.y+dy[k];
	if(nx<1 || nx>n || ny<1 || ny>m) return 0;
	if(!cap[nx][ny]) return 0;
	newnode=(Node){nx,ny,node.step+1};
	return 1;
}

void bfs(int sx,int sy,int number)
{
	while(!Q.empty()) Q.pop();
	memset(inQ,0,sizeof(inQ));
	Node start=(Node){sx,sy,1};
	dist[number][sx][sy]=1;
	Q.push(start); inQ[sx][sy]=1;
	while(!Q.empty())
	{
		Node now=Q.front(); Q.pop();
		Node newnode;
		for(int k=0;k<4;k++)
		{
			if(!expand(now,newnode,k)) continue;
			if(!inQ[newnode.x][newnode.y])
			{
				inQ[newnode.x][newnode.y]=1;
				Q.push(newnode);
				//if(newnode.x==1 || newnode.x==n || newnode.y==1 || newnode.y==m) return newnode.step;
				dist[number][newnode.x][newnode.y]=newnode.step;
			}
		}
	}
}

int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	scanf("%d%d\n",&m,&n);
	n=n*2+1; m=m*2+1;
	for(int i=1;i<=n;i++)
	{
		fgets(tmp+1,300,stdin);
		for(int j=1;j<=m;j++)
			if(tmp[j]==' ') cap[i][j]=1;
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d",cap[i][j]);
		printf("\n");
	}*/
	int res=0,number=0;
	for(int i=2;i<=n;i+=2)
	{
		if(cap[i][1]) bfs(i,1,++number);
		if(cap[i][m]) bfs(i,m,++number);
	}
	for(int j=2;j<=m;j+=2)
	{
		if(cap[1][j]) bfs(1,j,++number);
		if(cap[n][j]) bfs(n,j,++number);
	}
	//printf("%d\n",number);
	for(int i=2;i<=n;i+=2)
		for(int j=2;j<=n;j+=2)
			res=std::max(res,std::min(dist[1][i][j],dist[2][i][j]));
	//printf("%d\n",res);
	printf("%d\n",res/2);
	return 0;
}
