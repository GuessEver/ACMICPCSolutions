#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 100000 + 10;
const int V = 1000000 + 10;

int n, m, a[N], b[N];
int cnt[V];
int maxp;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		if(a[i] > maxp) maxp = a[i];
	}
	for(int i = maxp; i > 0; i--)
		if(cnt[i] % 2 == 1 && cnt[i-1])
		{
			cnt[i]--;
			cnt[i-1]++;
		}
	for(int i = maxp; i > 0; i--)
		for(int j = 1; j <= cnt[i] / 2; j++) b[++m] = i;
	long long res = 0;
	for(int i = 1; i <= m; i+= 2)
		res += 1ll * b[i] * b[i+1];
	std::cout << res << std::endl;
	return 0;
}
