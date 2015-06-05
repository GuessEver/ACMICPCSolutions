#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if(a[n] != 0) { puts("NO"); return 0; }
	if(n == 1) printf("YES\n%d\n", a[n]);
	else { // n >= 2 // 1 0 -> 0
		if(a[n-1] == 1)
		{
			puts("YES");
			for(int i = 1; i < n; i++) printf("%d->", a[i]);
			printf("%d\n", a[n]);
		}
		else if(n >= 3 && a[n-1] == 0)
		{
			if(a[n-2] == 0)
			{
				puts("YES");
				for(int i = 1; i < n - 2; i++) printf("%d->", a[i]);
				printf("(%d->%d)->%d\n", a[n-2], a[n-1], a[n]);
			}
			else if(a[n-2] == 1)
			{
				int k = -1;
				for(int i = n - 3; i >= 1; i--) if(a[i] == 0) { k = i; break; }
				if(k == -1) puts("NO");
				else {
					puts("YES");
					for(int i = 1; i < k; i++) printf("%d->", a[i]);
					printf("(%d->(", a[k]);
					for(int i = k + 1; i < n - 1; i++) printf("%d->", a[i]);
					printf("%d))->%d\n", a[n-1], a[n]);
				}
			}
		}
		else puts("NO");
	}
	return 0;
}
