#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef long long LL;

LL n;

bool check(LL x)
{
	while(x)
	{
		if(x % 10 == 8) return 1;
		x /= 10;
	}
	return 0;
}

int main()
{
	scanf("%I64d", &n);
	LL ans, old = n;
	if(n < 0)
	{
		n = abs(n);
		if(n >= 10)
		{
			ans = n % 10 - 8;
			if(ans <= 0) ans += 10;
		}
		else ans = n + 8;
	}
	else{
		ans = 8 - n % 10;
		if(ans <= 0) ans += 10;
	}
	for(int i = 1; i <= ans; i++)
		if(check(abs(old + i)))
		{
			ans = i;
			break;
		}
	printf("%I64d\n", ans);
	return 0;
}
