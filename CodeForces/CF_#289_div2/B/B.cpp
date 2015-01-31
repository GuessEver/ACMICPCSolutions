#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, k, a[110], col[110][110];
int cnt[110][110];

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= a[i]; j++)
			cnt[i][col[i][j]]++;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int t = 1; t <= k; t++)
				if(abs(cnt[i][t] - cnt[j][t]) > 1) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1, c = 1; j <= a[i]; j++)
		{
			col[i][j] = c;
			c++; if(c > k) c -= k;
		}
	if(!check()) puts("NO");
	else{
		puts("YES");
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j < a[i]; j++)
				printf("%d ", col[i][j]);
			printf("%d\n", col[i][a[i]]);
		}
	}
	return 0;
}
