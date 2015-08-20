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
}A, I;
Matrix mul(Matrix x, int y)
{
	if(y == 0) return I;
	if(y & 1) return mul(x * x, y / 2) * x;
	return mul(x * x, y / 2);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		A.init(); A.x = A.y = n + 1;
		I.init(); I.x = I.y = n + 1;
		for(int i = 1; i <= n + 1; i++) I.a[i][i] = 1;
		for(int i = 1; i <= n; i++)
		{
			int k; scanf("%d", &k);
			while(k--)
			{
				int x; scanf("%d", &x);
				A.a[i][x] = 1;
			}
		}
		for(int i = 1; i <= n + 1; i++) A.a[i][n+1] = 1;
		A = mul(A, m);
		int res = 1;
		for(int i = 1; i <= n; i++) (res += A.a[i][n+1]) %= mod;
		printf("%d\n", res);
	}
	return 0;
}
