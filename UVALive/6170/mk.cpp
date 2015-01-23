#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 29;
	while(T--)
	{
		long long a = (long long)rand();
		long long b = a + (long long)rand();
		//long long a = rand() % 100000;
		//long long b = a + rand() % 100000;
		long long c = a + b + (long long)rand() * rand();
		printf("%lld %lld %lld\n", a, b, c);
	}
	return 0;
}
