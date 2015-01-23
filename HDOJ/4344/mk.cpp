#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 7; printf("%d\n", T);
	while(T--)
	{
		long long n = (long long)rand();
		printf("%lld\n", n);
	}
	return 0;
}
