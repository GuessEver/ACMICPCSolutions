#include <cstdio>

int ans[500000];
int Cnt;

int solve(int &x)
{
	int t = x / -2;
	if(-2 * t > x) t++;
	int r = x - -2 * t;
	x = t;
	return r;
}

int main()
{
	freopen("1022.in", "r", stdin);
	freopen("1022.out", "w", stdout);
	int x; scanf("%d", &x);
	do {
		ans[Cnt++] = solve(x);
	}while(x);
	for(int i = Cnt - 1; i >= 0; i--) printf("%d", ans[i]);
	printf("\n");
	return 0;
}
