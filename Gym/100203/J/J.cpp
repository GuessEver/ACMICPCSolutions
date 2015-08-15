#include <cstdio>
#include <cstring>
const int N = 200 + 10;
int n, A, B;
int a[N];
bool vis[N];

int main()
{
	scanf("%d%d%d", &n, &A, &B);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		a[i] += x;
	}
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 0) continue;
		res++; int cnt = 1; a[i]--;
		memset(vis, 0, sizeof(vis));
		for(int j = i + 1; j <= n && cnt < A && j - i + 1 <= B; j++)
			if(a[j] == 2)
			{
				a[j]--;
				vis[j] = 1; cnt++;
			}
		for(int j = i + 1; j <= n && cnt < A && j - i + 1 <= B; j++)
			if(a[j] == 1 && !vis[j])
			{
				a[j]--;
				cnt++;
			}
		if(a[i] > 0) i--;
	}
	printf("%d\n", res);
	return 0;
}
