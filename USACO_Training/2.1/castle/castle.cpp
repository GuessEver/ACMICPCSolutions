/*
TASK: castle
LANG: C++
ID: jiangzh15
*/
/*
num		L R U D
1		L _ _ _ 
2		_ _ U _
3		L _ U _
4		_ R _ _
5		L R _ _
6		_ R U _
7		L R U _
8		_ _ _ D
9		L _ _ D
10		_ _ U D
11		L _ U D
12		_ R _ D
13		L R _ D
14		_ R U D
15		L R U D
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=50+10;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
int n,m;
struct Node{bool wall[4];/*LRUD*/}a[N][N];
int number,maxsize,hash[N][N],cnt[N*N];
bool can[N*N][N*N];

void read()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x; scanf("%d",&x);
			if(x==1) a[i][j]=(Node){1,0,0,0};
			else if(x==2) a[i][j]=(Node){0,0,1,0};
			else if(x==3) a[i][j]=(Node){1,0,1,0};
			else if(x==4) a[i][j]=(Node){0,1,0,0};
			else if(x==5) a[i][j]=(Node){1,1,0,0};
			else if(x==6) a[i][j]=(Node){0,1,1,0};
			else if(x==7) a[i][j]=(Node){1,1,1,0};
			else if(x==8) a[i][j]=(Node){0,0,0,1};
			else if(x==9) a[i][j]=(Node){1,0,0,1};
			else if(x==10) a[i][j]=(Node){0,0,1,1};
			else if(x==11) a[i][j]=(Node){1,0,1,1};
			else if(x==12) a[i][j]=(Node){0,1,0,1};
			else if(x==13) a[i][j]=(Node){1,1,0,1};
			else if(x==14) a[i][j]=(Node){0,1,1,1};
			else if(x==15) a[i][j]=(Node){1,1,1,1};
		}
}

void dfs(int x,int y)
{
	if(x<1 || x>n || y<1 || y>m) return;
	if(hash[x][y]) return;
	hash[x][y]=number;
	cnt[number]++;
	for(int k=0;k<4;k++)
		if(!a[x][y].wall[k])
			dfs(x+dx[k],y+dy[k]);
}

void predoing()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<1 || nx>n || ny<1 || ny>m) continue;
				can[hash[i][j]][hash[nx][ny]]=1;
			}
}

bool writeans(int i,int j,int maxremoving)
{
	int nx=i-1,ny=j;
	for(int ttt=1;ttt<=2;ttt++)
	{
		if(nx<1 || nx>n || ny<1 || ny>m || hash[i][j]==hash[nx][ny])
		{
			nx=i,ny=j+1;
			continue;
		}
		if(cnt[hash[nx][ny]]+cnt[hash[i][j]]==maxremoving)
		{
			printf("%d %d ",i,j);
			if(ttt==1) printf("N\n");
			else printf("E\n");
			return 1;
		}
		nx=i,ny=j+1;
	}
	return 0;
}

int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	read();
	
	//dfs求联通块数量和大小 
	number=0; maxsize=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(!hash[i][j])
		{
			number++;
			dfs(i,j);
			maxsize=std::max(maxsize,cnt[number]);
		}
		
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%5d",hash[i][j]);
		puts("");
	}*/
	printf("%d\n",number);
	printf("%d\n",maxsize);
	
	
	
	predoing();//处理出所有相邻的情况  存在can数组 
	
	int maxremoving=0;
	for(int i=1;i<=number;i++)
		for(int j=1;j<=number;j++) if(i!=j)
		{
			if(can[i][j] && cnt[i]+cnt[j]>maxremoving)
			{
				maxremoving=cnt[i]+cnt[j];
				//printf("%d(%d) %d(%d) max=%d\n",i,cnt[i],j,cnt[j],maxremoving);
			}
		}
	printf("%d\n",maxremoving);
	
	for(int j=1;j<=m;j++)
		for(int i=n;i>=1;i--)
		{
			if(writeans(i,j,maxremoving)) return 0;
		}
	
	return 0;
}
