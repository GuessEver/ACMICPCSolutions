#include <cstdio>
const int N = 100000 + 10;

int n, sum[N];
char a[N];
int g[N], pos[N];

inline int F(int x)
{
	return a[x] == '*' ? 1 : 3;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%s", a + 1);
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1];
		if(a[i] == '*') sum[i]++;
	}
	g[1] = F(1);
	pos[1] = 1;
	for(int i = 2; i <= n; i++)
		if(g[i-1] + (a[i] == '*' ? -1 : 1) < F(i))
		{
			g[i] = g[i-1] + (a[i] == '*' ? -1 : 1);
			pos[i] = pos[i-1];
		}
		else {
			g[i] = F(i);
			pos[i] = i;
		}
	int k = -1;
	for(int i = 1; i <= n; i++)
		if(k == -1 || g[i] < g[k]) k = i;
	//for(int i = 1; i <= n; i++) printf("%d ", g[i]);
	//printf("   k = %d\n", k);
	int r = k, l = pos[k];
	int tmp = 2 * (sum[r] - sum[l-1]) - (r - l + 3);
	//printf("[%d, %d], tmp = %d\n", l, r, tmp);
	if(tmp > 0)
	{
		int inside = sum[r] - sum[l-1];
		int steps = (sum[n] - inside) + (2 + r - l + 1 - inside);
		printf("%d\n", steps);
		printf("%d\n", l);
		printf("Shift+%d\n", r);
		for(int i = 1; i <= n; i++)
			if(i < l || i > r)
			{
				if(a[i] == '*') printf("Ctrl+%d\n", i);
			}
			else {
				if(a[i] == '.') printf("Ctrl+%d\n", i);
			}
	}
	else {
		printf("%d\n", sum[n]);
		for(int i = 1, flag = 0; i <= n; i++) if(a[i] == '*')
		{
			if(flag) printf("Ctrl+");
			printf("%d\n", i); flag = 1;
		}
	}
	return 0;
}
