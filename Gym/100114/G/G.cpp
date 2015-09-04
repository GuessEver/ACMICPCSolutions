#include <cstdio>
#include <iostream>

int n, m;
int a[100], b[100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	do {
		a[++m] = n & 1;
		n >>= 1;
	}while(n);
	b[m] = a[m];
	for(int i = m - 1; i >= 1; i--)
		b[i] = a[i] ^ b[i+1];
	//for(int i = m; i >= 1; i--) printf("%d", b[i]);
	long long ans = 0;
	for(int i = m; i >= 1; i--)
		ans = ans * 2 + b[i];
	std::cout << ans << std::endl;
	return 0;
}
