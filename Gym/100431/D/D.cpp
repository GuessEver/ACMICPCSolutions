#include <cstdio>
#include <algorithm>

int n, a[210], cmp[210][210];

bool solve()
{
	for(int j = n - 1; j >= 1; j--)
		for(int i = j; i < n; i++)
		{
			if(cmp[i][j] == 1)
			{
				if(a[i] < a[i+1]) std::swap(a[i], a[i+1]);
				else return 0;
			}
			else {
				if(a[i] > a[i+1]) return 0;
			}
		}
	return 1;
}

int main()
{
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) a[i] = i;
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d", &cmp[i][j]);
	if(!solve()) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; i++)
			printf("%d%s", a[i], i == n ? "\n" : " ");
	}
	return 0;
}
