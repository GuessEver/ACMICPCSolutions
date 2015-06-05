#include <cstdio>
#include <cstring>
#include <algorithm>

long long l, r;
int k;
int L[100], R[100];
long long f[100][2][2][10];

int predo(long long a, int *num)
{
	int len = 0;
	do num[++len] = a % 10; while(a /= 10);
	return len;
}

long long calc(int pos, bool d, bool u, int pre)
{
	if(pos == 0) return 1;
	long long &res = f[pos][d][u][pre];
	if(res != -1) return res;
	res = 0;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
	{
		if(i == 4 || (pre == 6 && i == 2)) continue;
		res += calc(pos-1, d && i == L[pos], u && i == R[pos], i);
	}
	return res;
}

int main()
{
	while(scanf("%lld%lld", &l, &r) == 2 && (l || r))
	{
		memset(f, -1, sizeof(f));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		int len = std::max(predo(l, L), predo(r, R));
		printf("%lld\n", calc(len, 1, 1, 0));
	}
	return 0;
}
