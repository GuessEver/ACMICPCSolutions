#include<cstdio>
#include<cstdlib>
#include<ctime>

void work()
{
	int n=5,m=5;
	char map[10][10];
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) map[i][j]='.';
	int a=rand()%n,b=rand()%n;
	map[a][b]='L';
	int x=rand()%n,y=rand()%n;
	while(x==a && y==b) x=rand()%n,y=rand()%n;
	map[x][y]='Q';
	int door=1;
	for(int i=0;i<door;i++)
	{
		x=rand()%n,y=rand()%n;
		while(map[x][y]!='.') x=rand()%n,y=rand()%n;
		map[x][y]='a'+i;
		x=rand()%n,y=rand()%n;
		while(map[x][y]!='.') x=rand()%n,y=rand()%n;
		map[x][y]='a'+i;
	}
	int dangerous=3;
	for(int i=1;i<=dangerous;i++)
	{
		x=rand()%n,y=rand()%n;
		while(map[x][y]!='.') x=rand()%n,y=rand()%n;
		map[x][y]='#';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) printf("%c",map[i][j]);
		puts("");
	}
}

int main()
{
	freopen("1002.in","w",stdout);
	srand(time(0));
	int t=3; printf("%d\n\n",t);
	while(t--) work(),printf("\n");
	return 0;
}
