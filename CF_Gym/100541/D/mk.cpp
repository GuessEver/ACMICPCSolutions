#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	printf("5\n");
	for(int i = 1; i <= 5; i++)
	{
		long long n = 1ll * rand() * rand(); n %= 1000;
		long long m = 1ll * rand() * rand(); m %= 1000;
		printf("%lld %lld\n", n, m);
	}
	return 0;
}
