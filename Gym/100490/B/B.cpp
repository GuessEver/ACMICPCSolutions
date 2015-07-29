#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
long long n, m;

bool check(long long x)
{
	long long cnt = 0;
	for(int i = 1; i <= m; i++)
		cnt += x / i;
	return cnt >= n;
}

int main()
{
	//freopen("bigset.in", "r", stdin);
	//freopen("bigset.out", "w", stdout);
	cin >> n >> m;
	long long low = 1, high = n, ans = low;
	while(low < high)
	{
		long long mid = low + (high - low) / 2;
		if(check(mid)) high = mid;
		else low = mid + 1;
	}
	cout << high << std::endl;
	return 0;
}
