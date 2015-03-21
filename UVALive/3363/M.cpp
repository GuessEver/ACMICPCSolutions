#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200 + 10;

int n;
char s[N];
int f[N][N];

int countDigit(int x)
{
	int res = 0;
	do{
		res++;
		x /= 10;
	}while(x);
	return res;
}

bool check(int l, int r, int k)
{
	for(int i = l, t = l; i <= r; i++, t++)
	{
		if(t == k + 1) t = l;
		if(s[i] != s[t]) return 0;
	}
	return 1;
}

int solve(int l, int r)
{
	if(l == r) return 1;
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = 0x3f3f3f3f;
	for(int k = l; k < r; k++) // [l, k] [k+1, r]
	{
		int tmp = solve(l, k) + solve(k+1, r);
		if((r-l+1) % (k-l+1) == 0 && check(l, r, k))
			tmp = std::min(tmp,	countDigit((r-l+1)/(k-l+1)) + solve(l, k) + 2);
		f[l][r] = std::min(f[l][r], tmp);
	}
	//printf("%d %d : %d\n", l, r, f[l][r]);
	return f[l][r];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1); n = strlen(s+1);
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(1, n));
	}
	return 0;
}
