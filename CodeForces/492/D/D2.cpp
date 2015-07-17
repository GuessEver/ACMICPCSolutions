#include <cstdio>

const int N = 100000 + 10;

int n, x, y, a[N];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	//long long round = 1ll * x / gcd(x, y) * y;
	//long long rx = round / y;
	//long long ry = round / x;
	//long long part = rx * x + ry * y;
	long long tx = y, ty = x;
	for(int i = 1; i <= n; i++)
	{
		while(1)
		{
			if(tx < ty)
			{
				a[i] -= x;
				tx += y;
				if(a[i] <= 0) { puts("Vanya"); break; }
			}
			else if(tx > ty)
			{
				a[i] -= y;
				ty += x;
				if(a[i] <= 0) { puts("Vova"); break; }
			}
			else if(tx == ty)
			{
				tx = ty = 0;
				a[i] -= (x + y);
				tx += y; ty += x;
				if(a[i] <= 0) { puts("Both"); break; }
			}
		}
	}
	return 0;
}
