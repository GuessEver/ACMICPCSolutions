#include <cstdio>
#include <cstring>
#include <algorithm>

int R[20];

int predo(int *num, int a)
{
	int len = 0;
	do num[++len] = a % 10; while(a /= 10);
	return len;
}

//int f[12][2][2][85][85][85]; // f[pos][d][u][now][mod][sum]  // calculate[l, r]
//int f[12][2][85][85][85]; // f[pos][u][now][mod][sum] // calculate[1, r] - calculate[1, l]
int f[12][85][85][85]; // f[pos][0][now][mod][sum]   let u = 0  // calculate[1, r] - calculate[1, l]
// when u = 1, just calculate it without *f
// just because u = 0 in most of the conditions

int calc(int pos, bool u, int now, int mod, int sum)
{
	if(pos == 0) return now == 0 && sum == mod;
	int res = f[pos][now][mod][sum];
	if(!u && res != -1) return res;
	res = 0;
	int st = 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
		res += calc(pos-1, u && i == R[pos], (now*10+i)%mod, mod, sum + i);
	if(!u) f[pos][now][mod][sum] = res;
	return res;
}

int solve(int x)
{
	if(x == 0) return 0;
	int len = predo(R, x);
	int res = 0;
	for(int i = 1; i <= 81; i++) res += calc(len, 1, 0, i, 0);
	return res;
}

int main()
{
	memset(f, -1, sizeof(f));
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		int l, r; scanf("%d%d", &l, &r);
		printf("Case %d: %d\n", cas, solve(r) - solve(l - 1));
	}
	return 0;
}
