#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;

int n, q;
int cap[N][N];
int hang[N], lie[N];

void H(int x, int y)
{
	std::swap(hang[x], hang[y]);
}
void L(int x, int y)
{
	std::swap(lie[x], lie[y]);
}
void P(int x, int y)
{
	printf("%d\n", cap[hang[x]][lie[y]]);
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &cap[i][j]);
	for(int i = 1; i <= n; i++) hang[i] = i;
	for(int j = 1; j <= n; j++) lie[j] = j;
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
