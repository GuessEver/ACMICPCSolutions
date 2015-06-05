#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int n, a[N], f[N], c[N];
int ans[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int len = 0;
		for(int i = 1; i <= n; i++)
		{
			int low = 1, high = len;
			while(low <= high)
			{
				int mid = low + (high - low) / 2;
				if(a[i] > c[mid]) low = mid + 1;
				else high = mid - 1;
			}
			f[i] = low;
			c[low] = a[i];
			if(low > len) len = low;
		}
		printf("%d\n", len);
		//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
		for(int pre = 0x3f3f3f3f, t = len, i = n; t >= 1 && i >= 1; i--)
		{
			if(f[i] == t && a[i] < pre)
			{
				pre = a[i];
				ans[t--] = a[i];
			}
		}
		for(int i = 1; i < len; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[len]);
	}
	return 0;
}
