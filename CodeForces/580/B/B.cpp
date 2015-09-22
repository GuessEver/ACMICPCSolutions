#include <cstdio>
#include <algorithm>
#include <iostream>
const int N = 100000 + 10;
int n, m;
struct Node{
	int m, s;
	bool operator < (const Node &b) const
	{
		return m < b.m;
	}
}a[N];
long long sum[N];

int find(int low, int high)
{
	int minValue = a[low].m, ans = low;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(a[mid].m - minValue >= m) high = mid - 1;
		else { low = mid + 1; ans = mid; }
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].m, &a[i].s);
	std::sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i].s;
	long long res = 0;
	for(int l = 1; l <= n; l++)
	{
		int r = find(l, n);
		if(sum[r] - sum[l-1] > res) res = sum[r] - sum[l-1];
	}
	std::cout << res << std::endl;
	return 0;
}
