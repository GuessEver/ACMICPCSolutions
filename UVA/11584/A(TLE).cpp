#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000 + 10;

int n, f[N][N];
bool p[N][N];
char s[N];

void pre()
{
	memset(p, 0, sizeof(p));
	for(int k = 1; k <= n; k++) // odd
		for(int i = 0; k - i >= 1 && k + i <= n; i++)
			if(s[k-i] == s[k+i]) p[k-i][k+i] = 1;
			else break;
	for(int k = 1; k < n; k++) if(s[k] == s[k + 1]) // even
		for(int i = 0; k - i >= 1 && k + i + 1 <= n; i++)
			if(s[k-i] == s[k+1+i]) p[k-i][k+1+i] = 1;
			else break;
}

// O(N*N*N) TLE!!!
int solve(int l, int r)
{
	if(p[l][r] || l == r) return 1;
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = 0x3f3f3f3f;
	for(int k = l; k < r; k++) // [l, k] U [k+1, r]
		f[l][r] = std::min(f[l][r], solve(l, k) + solve(k+1, r));
	return f[l][r];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1); n = strlen(s+1);
		pre();
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(1, n));
	}
	return 0;
}
