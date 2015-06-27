#include <cstdio>

const int N = 1000 + 10;

int n, a[N];

int calc(int from, int to, int flag)
{
	if(flag == 1) // clockwise
	{
		return ((to - from) % n + n) % n;
	}
	else { //counter-clockwise
		return ((from - to) % n + n) % n;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		a[i] = calc(x, i-1, i % 2);
		//printf("%d : %d\n", i, a[i]);
	}
	for(int i = 2; i <= n; i++)
		if(a[i] != a[1])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
