#include <cstdio>

const int dx[] = {1,-1,0,0,-1,-1,1,1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};

int X, Y, sx, sy;
char cap[500][500];

int main()
{
	freopen("1030.in", "r", stdin);
	freopen("1030.out", "w", stdout);
	scanf("%d%d", &Y, &X);
	scanf("%d%d", &sy, &sx);
	for(int i = X; i >= 1; i--)
		scanf("%s", cap[i]+1);
	int weeks = 0;
	cap[sx][sy] = 'M';
	bool can;
	do{
		weeks++;
#ifdef ______MYDEG
		for(int i = X; i >= 1; i--)
			puts(cap[i]+1);
		puts("");
#endif
		for(int i = 1; i <= X; i++)
			for(int j = 1; j <= Y; j++)
				if(cap[i][j] == 'M')
				{
					for(int k = 0; k < 8; k++)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if(cap[x][y] == '*') continue;
						if(cap[x][y] == '.') cap[x][y] = 'm';
					}
				}
		for(int i = 1; i <= X; i++)
			for(int j = 1; j <= Y; j++)
				if(cap[i][j] == 'm') cap[i][j] = 'M';
		can = 0;
		for(int i = 1; i <= X; i++)
			for(int j = 1; j <= Y; j++)
				if(cap[i][j] == '.') 
				{
					can = 1;
					break;
				}
	}while(can);
	printf("%d\n", weeks);
	return 0;
}
