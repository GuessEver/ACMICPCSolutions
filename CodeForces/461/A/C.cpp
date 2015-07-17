#include <cstdio>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

int n, a[300010];
long long sum = 0;

bool cmp(int a, int b) { return a > b; }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	std::sort(a+1, a+1+n, cmp);
	int l = 1, r = n, p = n + 1;
	long long res = 0;
	while(l <= r)
	{
		res += sum + a[p];
		sum -= a[r];
		p = r--;
	}
	cout << res << endl;
	return 0;
}
