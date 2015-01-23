#include <cstdio>

char day[][100] = {"Saturday", "Sunday", "Monday", 
	"Tuesday", "Wednesday", "Thursday", "Friday"};

int mul(int x, int y, int mod)
{
	int res = 1;
	int k = x;
	while(y)
	{
		if(y & 1) res = res * (k % mod) % mod;
		y >>= 1;
		res = res * res % mod;
	}
	return res % mod;
}

int main()
{
	freopen("Test.txt", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			int ans = mul(i % 7, i % 6, 7);
			//printf("%d ", ans);
			sum += ans;
			sum %= 7;
			if(i % 100000 == 0) printf("%d,", sum);
			if(i % 10000000 == 0)
				fprintf(stderr, "%d / %d\n", i,  n);
		}
	}
	return 0;
}
