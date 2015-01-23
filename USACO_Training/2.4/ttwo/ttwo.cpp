/*
LANG: C++
TASK: ttwo
ID: jiangzh15
*/
#include<cstdio>
const int dx[]={-1, 0,+1, 0};
const int dy[]={0, +1, 0,-1};

int n=10;
char cap[20][20];
struct Point{int x,y;}cow,far;
int vis[20][20];
int dir_c=0,dir_f=0;

bool inmap(int x,int y)
{
	return x>=0 && x<n && y>=0 && y<n;
}

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&cap[i]);
		for(int j=0;j<n;j++)
		{
			if(cap[i][j]=='C') cow=(Point){i,j};
			if(cap[i][j]=='F') far=(Point){i,j};
		}
	}
	int step=0;
	while(1)
	{
		if(++vis[cow.x][cow.y] > 100) {step=0;break;}
		if(++vis[far.x][far.y] > 100) {step=0;break;}
		if(cow.x==far.x && cow.y==far.y) break;
		
		int cx=cow.x+dx[dir_c],cy=cow.y+dy[dir_c];
		if(!inmap(cx,cy) || cap[cx][cy]=='*')
		{
			dir_c=(dir_c+1)%4;
			cx=cow.x; cy=cow.y;
		}
		int fx=far.x+dx[dir_f],fy=far.y+dy[dir_f];
		if(!inmap(fx,fy) || cap[fx][fy]=='*')
		{
			dir_f=(dir_f+1)%4; 
			fx=far.x; fy=far.y;
		}
		step++;
		cow=(Point){cx,cy};
		far=(Point){fx,fy};
	}
	printf("%d\n",step);
}
