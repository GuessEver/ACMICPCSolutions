#include <cstdio>
#include <cstring>
#include <algorithm>

int l, r;
int k;
int L[10], R[10];
int f[10][2][2][2100];

int predo(int a, int *num)
{
	int len = 0;
	do num[++len] = a % 10; while(a /= 10);
	return len;
}

bool check(int status, int &S, int k, bool zero)
{
	S = status;
	int tmp = (1 << k);
	if(k == 0 && zero) return 1;
	if(S & tmp) return 0;
	S |= tmp;
	return 1;
}

int calc(int pos, bool d, bool u, int status, bool zero)
{
	if(pos == 0) return 1;
	int &res = f[pos][d][u][status];
	if(res != -1) return res;
	res = 0;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
	{
		int S;
		if(!check(status, S, i, zero && i == 0)) continue;
		res += calc(pos-1, d && i == L[pos], u && i == R[pos], S, zero && i == 0);
	}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &l, &r);
		memset(f, -1, sizeof(f));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		int len = std::max(predo(l, L), predo(r, R));
		printf("%d\n", calc(len, 1, 1, 0, 1));
	}
	return 0;
}
