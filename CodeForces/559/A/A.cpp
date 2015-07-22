#include <cstdio>
#include <iostream>

int a[20], n = 6;

int main()
{
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int len = a[1] + a[2] + a[3];
	long long S = 1ll * len * len - 1ll * a[1] * a[1] - 1ll * a[3] * a[3] - 1ll * a[5] * a[5];
	std::cout << S << std::endl;
	return 0;
}
