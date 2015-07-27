#include <cstdio>
#include <cstring>
#include <algorithm>

long long l, r;
int k;
int L[100], R[100];
int Llen, Rlen, preZero;
long long f[100][2][2][60000];

int predo(long long a, int *num)
{
	int len = 0;
	do num[++len] = a % 10; while(a /= 10);
	return len;
}

bool solve(int st, int &S, int k, bool zero)
{
	int a[10] = {}; S = st;
	for(int i = 0; i < 10; i++)
	{
		a[i] = st % 3;
		st /= 3;
	}
	if(k == 0 && zero) return 1;
	else {
		if(a[k] >= 2) return 0;
		a[k]++;
	}
	S = 0;
	for(int i = 9; i >= 0; i--)
		S = S * 3 + a[i];
	return 1;
}

long long calc(int pos, bool d, bool u, int status, bool zero)
{
	if(pos == 0) return 1;
	long long &res = f[pos][d][u][status];
	if(res != -1) return res;
	res = 0;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
	{
		int S;
		if(!solve(status, S, i, zero)) continue;
		res += calc(pos-1, d && i == L[pos], u && i == R[pos], S, i == 0 && zero == 1);
	}
	return res;
}

int main()
{
	freopen("exchange.in", "r", stdin);
	freopen("exchange.out", "w", stdout);
	while(scanf("%I64d%I64d", &l, &r) == 2 && (l || r))
	{
		memset(f, -1, sizeof(f));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		Llen = predo(l, L);
		Rlen = predo(r, R);
		int len = std::max(Llen, Rlen);
		printf("%I64d\n", calc(len, 1, 1, 0, 1));
	}
	return 0;
}
