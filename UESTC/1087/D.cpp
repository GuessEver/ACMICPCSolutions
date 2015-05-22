#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N];

bool check(int mid, long long &first, long long &second)
{
	bool flag = 0;
	first = second = 0;
	for(int i = 0; i < n - 1; i++)
	{
		int st = std::lower_bound(a, a+n, a[i] + mid) - a;
		int ed = std::upper_bound(a, a+n, a[i] + mid) - a;
		int sign = 0;
		if(a[st] == a[i] + mid) flag = 1; //else st--;
		first += ed - i - 1;
		second += n - st + sign;
		//printf("i = %d, (%lld, %lld)\n", i, first, second);
	}
	//printf("flag = %d\n", flag);
	return flag;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		std::sort(a, a+n);
		long long std_first = 1ll * n * (n - 1) / 2 / 2 + 1;
		long long std_second = 1ll * n * (n - 1) / 2 / 2 + 1;
		if(1ll * n * (n - 1) / 2 % 2 == 0) std_first--;
		int low = 0, high = a[n-1] - a[0], ans = high;
		long long first, second; // first [<= mid], second [>= mid]
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			//printf("[%d, %d]  mid = %d\n", low, high, mid);
			bool flag = check(mid, first, second);
			if(first < std_first) low = mid + 1;
			else if(second < std_second) high = mid - 1;
			else {
				high = mid - 1;
				if(flag) ans = mid;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
