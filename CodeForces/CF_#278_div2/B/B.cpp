#include <cstdio>
#include <algorithm>

int n, a[10], b[10];

bool check()
{
	for(int i = 1; i <= 4; i++) b[i] = a[i];
	std::sort(b+1, b+1+4);
	return b[4] == 3 * b[1] && b[1] + b[4] == b[2] + b[3];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+1+n);
	if(n == 4)
	{
		if(check()) puts("YES");
		else puts("NO");
	}
	else if(n == 1) printf("YES\n%d\n%d\n%d\n", a[1]*2, a[1]*2, a[1]*3);
	else if(n == 2)
	{
		a[4] = 3 * a[1];
		if(a[2] > a[4]) { puts("NO"); return 0; }
		a[3] = a[1] + a[4] - a[2];
		printf("YES\n%d\n%d\n", a[3], a[4]);
	}
	else if(n == 3)
	{
		int maxp = std::max(a[1], std::max(a[2], a[3]));
		for(int i = 1; i <= 3*maxp; i++)
		{
			a[4] = i;
			if(check()) { printf("YES\n%d\n", i); return 0; }
		}
		puts("NO");
	}
	else if(n == 0) printf("YES\n1\n2\n2\n3\n");
	return 0;
}
