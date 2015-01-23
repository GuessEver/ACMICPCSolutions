#include<cstdio>
#include<cstdlib>
#include<queue>
#include<map>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

struct status{int hash,step,last;int map[6][6];}first;
queue<status> q;
map<int,bool> h[3];

int gethash(status a)//三进制hash值
{
	int res=0,k=1;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			res+=a.map[i][j]*k;
			k*=3;
		}
	return res;
}

bool check(status a)
{
	for(int i=1;i<=4;i++)//行
	{
		int flag=1;
		for(int j=2;j<=4;j++)
			if(a.map[i][j-1]!=a.map[i][j]) flag=0;
		if(flag) return 1;
	}
	for(int j=1;j<=4;j++)//列
	{
		int flag=1;
		for(int i=2;i<=4;i++)
			if(a.map[i][j]!=a.map[i-1][j]) flag=0;
		if(flag) return 1;
	}
	//斜线
	if(a.map[1][1]==a.map[2][2] && a.map[2][2]==a.map[3][3] && a.map[3][3]==a.map[4][4]) return 1;
	if(a.map[1][4]==a.map[2][3] && a.map[2][3]==a.map[3][2] && a.map[3][2]==a.map[4][1]) return 1;
	return 0;
}

void move(status now,int x,int y,int k)
{
	status tmp=now;
	int tmpx=x+dx[k];
	int tmpy=y+dy[k];
	if(tmpx<1||tmpx>4) return;
	if(tmpy<1||tmpy>4) return;
	if(tmp.map[tmpx][tmpy]==tmp.last) return;//必须黑白交替走
	tmp.last=3-tmp.last;
	swap(tmp.map[x][y],tmp.map[tmpx][tmpy]);
	tmp.hash=gethash(tmp);
	tmp.step++;
	if(check(tmp)) {printf("%d\n",tmp.step);exit(0);}
	if(!h[tmp.last][tmp.hash])
	{
		h[tmp.last][tmp.hash]=1;
		q.push(tmp);
	}
}

void bfs()
{
	first.hash=gethash(first);
	first.last=1; q.push(first);
	first.last=2; q.push(first);
	while(!q.empty())
	{
		status now=q.front(); q.pop();
		int x1=-1,x2=-1,y1=-1,y2=-1;//两个空白的格子
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				if(now.map[i][j]==0)
				{
					if(x1==-1&&y1==-1){x1=i;y1=j;}
					else{x2=i;y2=j;}
				}
		for(int k=0;k<4;k++)
		{
			move(now,x1,y1,k);
			move(now,x2,y2,k);
		}
	}
}

int main()
{
	freopen("1004.in","r",stdin);
	for(int i=1;i<=4;i++)
	{
		char s[10];scanf("%s",s);
		for(int j=0;j<4;j++)
		{
			if(s[j]=='B') first.map[i][j+1]=1;
			else if(s[j]=='W') first.map[i][j+1]=2;
		}
	}
	bfs();
	return 0;
}
