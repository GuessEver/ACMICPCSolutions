#include <cstdio>

int n, a[200], b[200];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%1d", &a[i]);
		b[i] = a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1) a[i] += 1;
		a[i+1] += a[i] / 2;
		a[i] %= 2;
		cnt += (b[i] != a[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
