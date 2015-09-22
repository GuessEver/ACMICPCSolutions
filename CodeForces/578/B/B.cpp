#include <cstdio>
#include <iostream>
const int N = 200000 + 10;
int n, k, x, a[N];
long long L[N], R[N];

int main()
{
	scanf("%d%d%d", &n, &k, &x);
	long long mul = 1;
	for(int i = 1; i <= k; i++) mul *= x;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) L[i] = L[i-1] | a[i];
	for(int i = n; i >= 1; i--) R[i] = R[i+1] | a[i];
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		long long tmp = L[i-1] | (a[i] * mul) | R[i+1];
		if(tmp > res) res = tmp;
	}
	std::cout << res << std::endl;
	return 0;
}
