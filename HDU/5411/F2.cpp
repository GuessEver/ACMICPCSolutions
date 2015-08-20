#include <cstdio>
#include <cstring>
const int N = 50 + 10;
const int mod = 2015;

int n, m;
struct Matrix{
	int a[N][N], x, y;
	Matrix() { memset(a, 0, sizeof(a)); x = y = 0; }
	void init() { memset(a, 0, sizeof(a)); x = y = 0; }
	Matrix operator * (const Matrix &b) const
	{
		Matrix res;
		res.x = x; res.y = b.y;
		for(int i = 1; i <= x; i++)
			for(int j = 1; j <= y; j++)
				for(int k = 1; k <= b.y; k++)
					(res.a[i][k] += 1ll * a[i][j] * b.a[j][k] % mod) %= mod;
		return res;
	}
}A, B;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		A.init(); B.init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) A.a[1][i] = 1;
		A.x = 1; A.y = n;
		B.x = B.y = n;
		for(int i = 1; i <= n; i++)
		{
			int k; scanf("%d", &k);
			while(k--)
			{
				int x; scanf("%d", &x);
				B.a[x][i] = 1;
			}
		}
		int res = 1;
		for(int i = 1; i <= n; i++) (res += A.a[1][i]) %= mod;
		for(int i = 1; i < m; i++)
		{
			A = A * B;
			for(int i = 1; i <= n; i++) (res += A.a[1][i]) %= mod;
		}
		printf("%d\n", res);
	}
	return 0;
}
