#include <cstdio>

const int N = 100000 + 10;
const int mod = 1000000000 + 7;

int n;
int cnt['Z' + 10];

int mul(int x, int y)
{
	if(y == 0) return 1;
	if(y & 1) return mul(1ll * x * x % mod, y / 2) * 1ll * x % mod;
	return mul(1ll * x * x % mod, y / 2) % mod;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char ch; scanf(" %c", &ch);
		cnt[ch]++;
	}
	int maxx = 0, num = 0;
	for(int i = 'A'; i <= 'Z'; i++)
	{
		if(cnt[i] > maxx)
		{
			maxx = cnt[i];
			num = 0;
		}
		if(cnt[i] == maxx) num++;
	}
	printf("%d\n", mul(num, n));
	return 0;
}
