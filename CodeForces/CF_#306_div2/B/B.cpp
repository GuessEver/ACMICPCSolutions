#include <cstdio>

int n, l, r, x, a[20];
bool choose[20];
int cnt = 0;

bool check()
{
	int kmin = -1, kmax = -1, sum = 0;
	for(int i = 1; i <= n; i++) if(choose[i])
	{
		if(kmin == -1 || a[i] < a[kmin]) kmin = i;
		if(kmax == -1 || a[i] > a[kmax]) kmax = i;
		sum += a[i];
	}
	if(kmin == -1 || kmax == -1 || kmin == kmax) return 0;
	if(sum < l || sum > r) return 0;
	if(a[kmax] - a[kmin] < x) return 0;
	return 1;
}

void dfs(int x)
{
	if(x > n)
	{
		if(check()) cnt++;
		return;
	}
	choose[x] = 0;
	dfs(x + 1);
	choose[x] = 1;
	dfs(x + 1);
}

int main()
{
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}
