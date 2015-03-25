#include <cstdio>

int n, a[1010];

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if(a[i] + a[j] == 0) return 1;
	return 0;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if(check()) puts("NOT UNIQUE"); else puts("UNIQUE");
	}
	return 0;
}
