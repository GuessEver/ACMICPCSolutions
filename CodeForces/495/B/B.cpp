#include <cstdio>
#include <cmath>

int a, b;

bool in(int x)
{
	return x >= b+1 && x <= a-b;
}

int main()
{
	scanf("%d%d", &a, &b);
	if(a - b == 0)
	{
		puts("infinity");
		return 0;
	}
	if(a < b)
	{
		puts("0");
		return 0;
	}
	// [b + 1, a - b]
	int cnt = 0;
	int k = sqrt(1.0*(a-b));
	for(int i = 1; i <= k; i++)
	{
		if((a-b) % i != 0) continue;
		if(in(i)) cnt++;
		if(i == (a-b)/i) continue;
		if(in((a-b)/i)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
