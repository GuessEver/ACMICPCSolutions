#include <cstdio>
#include <algorithm>
const int N = 500000 + 10;
int n, a[N];

int solve(int L, int R)
{
	//printf("L = %d, R = %d\n", L, R);
	int res = 0;
	for(int i = L + 1; i < R; i++)
	{
		if(a[L] == 0 && a[R] == 0)
		{
			res += a[i];
			a[i] = 0;
		}
		else if(a[L] == 0 && a[R] == 1)
		{
			res += a[i];
			if(i <= (L + R) / 2) a[i] = 0;
			else a[i] = 1;
		}
		else if(a[L] == 1 && a[R] == 0)
		{
			res += a[i] == 0;
			if(i <= (L + R) / 2) a[i] = 1;
			else a[i] = 0;
		}
		else { // a[L] == 1 && a[R] == 0
			res += a[i] == 0;
			a[i] = 1;
		}
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[n + 1] = a[n];
	int cnt = 0, pre = 1;
	for(int i = 3; i <= n; i++)
	{
		if(a[i] == a[i-1]) pre = i;
		else if(a[i] == a[i+1])
		{
			if(pre + 1 < i) cnt = std::max(cnt, solve(pre, i));
			pre = i;
		}
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}
