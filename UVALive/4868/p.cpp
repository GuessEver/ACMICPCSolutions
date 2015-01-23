#include <cstdio>
#include <cstring>

long long n;
char s[20];
int len;

bool check(long long x)
{
	long long y = 0;
	long long t = x;
	for(int i = 1; i <= len; i++)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}
	return t == y;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		if(!strcmp(s, "0")) break;
		len = strlen(s);
		sscanf(s, "%lld", &n);
		long long ans = 0;
		while(!check(n))
		{
			n++;
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
