#include <cstdio>

char day[7][100] = {"Saturday", "Sunday", "Monday", 
	"Tuesday", "Wednesday", "Thursday", "Friday"};
int f[100];

int mul(int x, int y, int mod)
{
	if(x == 0) return 0;
	if(y == 0) return 1;
	if(y == 1) return x;
	if(y&1) return mul(x * x % mod, y / 2, mod) * x % mod;
	else return mul(x * x % mod, y / 2, mod) % mod;
}

int main()
{
	for(int i = 1; i <= 42; i++)
	{
		f[i] = f[i-1] + mul(i % 7, i % 6, 7);
		f[i] %= 7;
		//printf("%d ", f[i] % 7);
		//if(i % 42 == 0) printf("\n");
		//printf("%d\n", f[i] % 7);
	}
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int ans = (int)(((long long)n / 42 * f[42] + f[n % 42]) % 7);
		//printf("ans = %d\n", ans);
		puts(day[ans]);
	}
	return 0;
}
