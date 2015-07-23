#include <cstdio>

FILE *fin = fopen("I.in", "r");
FILE *ans = fopen("I.out", "r");

int n, a[1000000];
int vis[1000000];

int calc(int x, char op, int y)
{
	if(op == '+') return x + y;
	if(op == '-') return x - y;
	if(op == '*') return x * y;
	if(op == '/') return x / y;
}

bool check()
{
	for(int i = 1; i < n; i++)
	{
		int x, y; char op;
		fscanf(ans, "%d %c %d", &x, &op, &y);
		if(x >= n + i || y >= n + i) return 0;
		if(vis[x] || vis[y]) return 0;
		vis[x] = vis[y] = 1;
		a[n+i] = calc(a[x], op, a[y]);
	//	printf("a[%d] = %d\n", n+i, a[n+i]);
	}
	return a[2*n-1] == 24;
}

int main()
{
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) a[i] = n;
	if(check()) puts("ok"); else puts("no");
	return 0;
}
