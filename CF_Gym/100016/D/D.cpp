#include <cstdio>

int n, m;

int calc(int R)
{
	int x = R * (R-1) / 2;
	int tmp = x/R*3;
	if(x % R != 0) tmp++;
	if(tmp < R-1) tmp = R-1;
	return tmp;
}

int main()
{
	freopen("group.in", "r", stdin);
	scanf("%d%d", &n, &m);
	int ans = 3 * (n-m-1) + calc(m+1);
	printf("%d %d\n", n-m, ans);
	return 0;
}
