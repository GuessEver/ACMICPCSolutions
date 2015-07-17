#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 300 + 10;
const long long mod = 1000000000 + 9;

int n, K;
long long f[N][N][N];

int main()
{
	scanf("%d%d", &n, &K);
	f[1][0][0] = f[1][1][1] = 1;
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= K; j++)
			for(int k = 0; k <= K; k++)
			{
				f[i+1][j][k] += f[i][j][k];
				f[i+1][j][k] %= mod;
				f[i+1][j+1][std::max(j+1, k)] += f[i][j][k];
				f[i+1][j+1][std::max(j+1, k)] %= mod;
				f[i+1][j-1][k] += f[i][j][k];
				f[i+1][j-1][k] %= mod;
			}
	printf("%lld\n", f[n][0][K] % mod);
	return 0;
}
