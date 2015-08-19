#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;

int n, a[N];

int main()
{
	freopen("irreducible.in", "r", stdin);
	freopen("irreducible.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	//for(int i = n; i >= 1; i--) a[i] = (a[i] - a[i+1]) % 2 + a[i+1];
	int m = 0;
	for(int i = n; i >= 1; i--)
	{
		if((a[i] - m) % 2 == 0) m = std::max(0, m - 1);
		else m++;
	}
	puts("1");
	if(m == 0) printf("0\n");
	else {
		printf("%d", m);
		for(int i = m; i >= 1; i--) printf(" %d", i);
		puts("");
	}
	return 0;
}
