#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 50000 + 10;
const int pri[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149}; // pri[35]

int n, m;
long long val[40][N*4], mul[40][N*4];
int num[40];

void factor(int x)
{
	memset(num, 0, sizeof(num));
	for(int i = 0; i < 35 && x > 1; i++)
		if(x % pri[i] == 0)
			while(x % pri[i] == 0)
			{
				num[i]++;
				x /= pri[i];
			}
}

long long Mul(long long x, long long y, long long p)
{
	if(y == 0) return 1 % p;
	if(y & 1) return Mul(x * x % p, y / 2, p) % p * x % p;
	return Mul(x * x % p, y / 2, p) % p;
}

void change(int p, int l, int r, int a, int b, int c, long long *sum, long long *add)
{
	if(a <= l && b >= r)
	{
		add[p] += c;
		return;
	}
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int m = l + (r - l) / 2;
	if(a <= m) change(p*2, l, m, a, b, c, sum, add);
	if(b > m) change(p*2+1, m+1, r, a, b, c, sum, add);
	sum[p] = sum[p*2] + add[p*2] * (m - l + 1)
		+ sum[p*2+1] + add[p*2+1] * (r - m);
}

long long query(int p, int l, int r, int a, int b, long long *sum, long long *add)
{
	if(a <= l && b >= r) return sum[p] + add[p] * (r - l + 1);
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int m = l + (r - l) / 2;
	long long x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b, sum, add);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b, sum, add);
	sum[p] = sum[p*2] + add[p*2] * (m - l + 1)
		+ sum[p*2+1] + add[p*2+1] * (r - m);
	return x1 + x2;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(val, 0, sizeof(val));
		memset(mul, 0, sizeof(mul));
		scanf("%d%d", &n, &m);
		while(m--)
		{
			int op, x, y, p;
			scanf("%d%d%d%d", &op, &x, &y, &p);
			if(op == 0)
			{
				long long res = 1;
				for(int i = 0; i < 35; i++)
				{
					long long cnt = 0;
					if(x <= y) cnt = query(1, 1, n, x, y, val[i], mul[i]);
					else cnt = query(1, 1, n, x, n, val[i], mul[i])
						+ query(1, 1, n, 1, y, val[i], mul[i]);
					res = res * Mul(1ll * pri[i], cnt, 1ll * p) % p;
				}
				std::cout << res << std::endl;
			}
			else {
				int sign = op == 1 ? 1 : -1;
				factor(p);
				for(int i = 0; i < 35; i++) if(num[i])
				{
					if(x <= y) change(1, 1, n, x, y, sign * num[i], val[i], mul[i]);
					else {
						change(1, 1, n, x, n, sign * num[i], val[i], mul[i]);
						change(1, 1, n, 1, y, sign * num[i], val[i], mul[i]);
					}
				}
			}
		}
	}
	return 0;
}
