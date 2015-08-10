#include <cstdio>
#include <cstring>
#include <algorithm>

int l, r, n;
int k;
int L[20], R[20];
int f[20][2][2][100], num[100];
int S[100];

int predo(int a, int *num)
{
	int len = 0;
	do num[++len] = a % 10; while(a /= 10);
	return len;
}

long long calc(int pos, bool d, bool u, int sum)
{
	if(pos == 0) return sum == 0;
	int &res = f[pos][d][u][sum];
	if(res != -1) return res;
	res = 0;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
	{
		if(sum - i < 0) continue;
		res += calc(pos-1, d && i == L[pos], u && i == R[pos], sum - i);
	}
	return res;
}

int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int dp[20][100];
int get(int k, int sum)
{
	int res = 0;
	for(int i = 10; i >= 1; i--)
		for(int t = 0; t <= 9; t++)
		{
			if(dp[i - 1][sum - t] < k)
				k -= dp[i - 1][sum - t];
			else {
				res += t * pow10[i-1];
				sum -= t;
				break;
			}
		}
	return res;
}
int solve(int sum)
{
	int low = 1, high = dp[10][sum];
	while(low <= high)
	{
		int k = low + (high - low) / 2;
		int ak = get(k, sum);
		if(ak < S[sum-1] + k) low = k + 1;
		else if(ak > S[sum-1] + k) high = k - 1;
		else return 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	l = 1, r = 9;
	for(int i = 1; i <= 9; i++)
	{
		memset(f, -1, sizeof(f));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		int len = std::max(predo(l, L), predo(r, R));
		for(int j = 0; j <= 9 * 9; j++) dp[i][j] += calc(len, 1, 1, j);
		//l *= 10;
		r = (r + 1) * 10 - 1;
		if(r > n) r = n;
	}
	for(int j = 0; j <= 9 * 9; j++) dp[10][j] = dp[9][j];
	if(n == 1000000000) dp[10][1]++;
	S[0] = dp[10][0];
	for(int i = 0; i <= 10; i++) dp[i][0] = 1;
	for(int j = 1; j <= 9 * 9; j++) S[j] = S[j-1] + dp[10][j];
	//for(int i = 1; i <= 9; i++)
	//	for(int j = 0; j <= 9 * 9; j++) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	int res = 0;
	//printf("%d\n", solve(1));
	//printf("%d\n", solve(6));
	//printf("%d\n", solve(16));
	for(int j = 0; j <= 9 * 9; j++) res += solve(j);
	printf("%d\n", res);
	return 0;
}
