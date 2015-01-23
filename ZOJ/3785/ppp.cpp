#include <cstdio>

char day[][100] = {"Saturday", "Sunday", "Monday", 
	"Tuesday", "Wednesday", "Thursday", "Friday"};

int mul(int x, int y, int mod)
{
	if(x == 0) return 0;
	if(y == 0) return 1;
	if(y == 1) return x;
	if(y & 1) return mul(x*x%mod, y/2, mod) * x % mod;
	else return mul(x*x%mod, y/2, mod);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			sum += mul(i, i, 7);
			sum %= 7;
			//printf("%d\n", sum);
		}
		puts(day[sum % 7]);
	}
	return 0;
}
