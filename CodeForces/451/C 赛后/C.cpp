#include <cstdio>
#include <algorithm>
using std::max;

typedef long long LL;

LL n, k, d1, d2;
LL a, b, c;

bool solve(LL d1, LL d2)
{
	if(n % 3 != 0) return 0;
	LL x = (k + 2 * d1 + d2);
	if(x % 3 != 0) return 0;
	x /= 3;
	a = x; b = a - d1; c = b - d2;
	//printf("%I64d %I64d %I64d\n", a, b, c);
	if(a < 0 || b < 0 || c < 0) return 0;
	if(a + b + c != k) return 0;
	if(max(max(a, b), c) <= n / 3) return 1;
	else return 0;
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
		bool flag = 0;
		flag |= solve(d1, d2);
		flag |= solve(-d1, d2);
		flag |= solve(d1, -d2);
		flag |= solve(-d1, -d2);
		puts(flag ? "yes" : "no");
	}
	return 0;
}
