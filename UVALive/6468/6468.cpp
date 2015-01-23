#include <cstdio>

int mod;

void solve()
{
	scanf("%d", &mod);
	int a = 1, b = 1, c;
	int leng = 2;
	//printf("1 1 ");
	while(1)
	{
		leng++;
		c = ((a % mod) + (b % mod)) % mod;
		//printf("%d ", c);
		if(b == 0 && c == 1) break;
		a = b; b = c;
	}
	//puts("");
	printf("%d\n", leng-1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		solve();
	}
	return 0;
}
