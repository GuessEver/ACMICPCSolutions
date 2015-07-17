#include <cstdio>
#include <cstring>

const int N = 300 + 10;
const long long mod = 1000000000 + 9;

int n, K;
long long f[N][N][N];

long long calc(int i, int j, int k)
{
	if(i == k) return i == j;
	if(!(i > k && k >= j && j >= 0)) return 0;
	if(i == 1) return 1; // f[1][0][0]
	if(f[i][j][k] != -1) return f[i][j][k];
	f[i][j][k] = ((calc(i-1, j, k)
		+ calc(i-1, j-1, k)) % mod //+ calc(i-1, j-1, k-1)
		+ calc(i-1, j+1, k)) % mod;// + calc(i-1, j+1, k+1);
	if(j == k) f[i][j][k] += calc(i-1, j-1, k-1);
	//if(f[i-1][j-1][k] == 0) f[i][j][k] += calc(i-1, j-1, k-1);
	return f[i][j][k] % mod;
}

int main()
{
	scanf("%d%d", &n, &K);
	memset(f, -1, sizeof(f));
	printf("%lld\n", calc(n, 0, K) % mod);
	//printf("!!");
	return 0;
}
