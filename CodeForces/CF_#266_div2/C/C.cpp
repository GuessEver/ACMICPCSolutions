#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;

const int N = 5 * 100000 + 10;

int n;
long long sum[N];
long long ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		sum[i] = sum[i-1] + a;
	}
	if(sum[n] % 3 != 0) { puts("0"); return 0; }
	long long avg = sum[n] / 3;
	long long avg2 = avg * 2;
	long long tmp = 0;
	for(int i = 1; i < n; i++)
	{
		if(sum[i] == avg2) ans += tmp;
		if(sum[i] == avg) tmp++;
	}
	cout << ans << endl;
	return 0;
}
