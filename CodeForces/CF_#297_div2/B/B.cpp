#include <cstdio>
#include <cstring>

const int N = 200000 + 10;

int n, m;
char s[N], res[N];
int cnt[N];

void dfs(int l, int r, int turn)
{
	if(l > r) return;
	int tmp = (cnt[l] + cnt[r] + turn) % 2;
	if(tmp == 0)
	{
		res[l] = s[l];
		res[r] = s[r];
	}
	else{
		res[l] = s[r];
		res[r] = s[l];
	}
	dfs(l+1, r-1, tmp);
}

int main()
{
	scanf("%s", s+1);
	n = strlen(s+1);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	dfs(1, n, 0);
	puts(res+1);
	return 0;
}
