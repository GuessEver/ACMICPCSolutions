#include <cstdio>

const int N = 1000 + 10;

int n, q;
int cap[N][N];
int tmpx[N], tmpy[N];

void P(int x, int y)
{
	printf("%d\n", cap[x][y]);
}
void H(int x, int y)
{
	for(int i = 1; i <= n; i++) tmpx[i] = cap[x][i];
	for(int i = 1; i <= n; i++) tmpy[i] = cap[y][i];
	for(int i = 1; i <= n; i++) cap[y][i] = tmpx[i];
	for(int i = 1; i <= n; i++) cap[x][i] = tmpy[i];
}

void L(int x, int y)
{
	for(int i = 1; i <= n; i++) tmpx[i] = cap[i][x];
	for(int i = 1; i <= n; i++) tmpy[i] = cap[i][y];
	for(int i = 1; i <= n; i++) cap[i][y] = tmpx[i];
	for(int i = 1; i <= n; i++) cap[i][x] = tmpy[i];
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("Ap.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &cap[i][j]);
	while(q--)
	{
		char op[10]; int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'A') P(x, y);
		else if(op[0] == 'R') H(x, y);
		else if(op[0] == 'C') L(x, y);
	}
	return 0;
}
