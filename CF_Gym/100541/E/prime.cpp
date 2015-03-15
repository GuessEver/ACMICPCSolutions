#include <cstdio>

bool check(int x)
{
	for(int i = 2; i < x; i++) if(x % i == 0) return 0;
	return 1;
}

int main()
{
	int cnt = 0;
	for(int i = 2; i <= 150; i++)
		if(check(i)) { ++cnt; printf("%d,", i); }
	printf("\n cnt = %d\n", cnt);
	return 0;
}
