#include <cstdio>
#include <cstring>

int n;
char str[1000];

long long solve(int x)
{
	if(x == 1) return 1;
	sprintf(str, "%d", x);
	int size = strlen(str);
	long long res = 1ll * (x - x/10) * (size - 1);
	res += solve(x / 10);
	return res;
}

int main()
{
	scanf("%d", &n);
	int k = 1000000000;
	while(n < k) k /= 10;
	long long res = solve(k);
	sprintf(str, "%d", k);
	res += 1ll * (n - k) * strlen(str);
	if(n >= 10) res--;
	if(k >= 10) res += strlen(str);
	printf("%I64d\n", res);
	return 0;
}
