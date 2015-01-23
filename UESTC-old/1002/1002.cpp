#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
using std::queue;
const int N=50+10;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m;
char g[N][N];
struct Point{
	int x,y;
	Point()	{x=-1; y=-1;}
	void init(int a,int b) { x=a; y=b; }
	bool used() 
	{
		return x!=-1 && y!=-1;
	}
}door['z'+10][2];
int sx,sy,tx,ty;
struct Qnode{
	int x,y,step;
	bool operator == (const Qnode &a) const
	{
		return a.x==x && y==a.y;
	}
}start,target;
queue<Qnode> Q;
bool vis[N][N];

void carry(int &x,int &y)
{
	int d=g[x][y]-'a',k=0;
	if(door[d][0].x==x && door[d][0].y==y) k=1;
	x=door[d][k].x; y=door[d][k].y;
}

bool expand(Qnode cur,Qnode &nex,int k)
{
	int x=cur.x+dx[k];
	int y=cur.y+dy[k];
	if(x<0||x>=n||y<0||y>=m) return 0;
	if(g[x][y]=='#') return 0;
	if(isalpha(g[x][y])) carry(x,y);
	nex=(Qnode){x,y,cur.step+1};
	return 1;
}

int bfs()
{
	target=(Qnode){tx,ty,0};
	start=(Qnode){sx,sy,0};
	Q.push(start); vis[sx][sy]=1;
	while(!Q.empty())
	{
		Qnode cur=Q.front();Q.pop();
		Qnode nex;
		//printf("(%d,%d) %d \n",cur.x,cur.y,cur.step);
		for(int k=0;k<4;k++)
		{
			if(!expand(cur,nex,k)) continue;
			if(nex==target) return nex.step;
			if(!vis[nex.x][nex.y])
			{
				vis[nex.x][nex.y]=1;
				Q.push(nex);
			}
		}
	}
	return -1;
}

int solve()
{
	memset(g,0,sizeof(g));
	memset(door,-1,sizeof(door));
	memset(vis,0,sizeof(vis));
	while(!Q.empty()) Q.pop();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",g[i]);
		for(int j=0;j<m;j++)
		{
			if(g[i][j]=='L') sx=i,sy=j,g[i][j]='.';
			if(g[i][j]=='Q') tx=i,ty=j,g[i][j]='.';
			if(isalpha(g[i][j]))
			{
				int k=0, p=g[i][j]-'a';
				if(door[p][k].used()) k=1;
				door[p][k].init(i,j);
			}
		}
	}
	return bfs();
}

int main()
{
	freopen("1002.in","r",stdin);
	freopen("1002.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--) printf("%d\n",solve());
	return 0;
}
