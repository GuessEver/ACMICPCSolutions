#include <cstdio>
#include <cstring>
#include <cstdlib>

long long a, m;
bool h[100100];

bool solve()
{
	memset(h, 0, sizeof(h));
	while(1)
	{
		if(a % m == 0) return 1;
		if(h[a%m]) return 0;
		h[a%m] = 1;
		a += a % m;
	}
}

int main()
{
	scanf("%I64d%I64d", &a, &m);
	if(solve()) puts("Yes");
	else puts("No");
	return 0;
}
