#include <cstdio>
#include <cstring>

const int N = 10000 + 10;

int n, a[N], L[N], R[N], c[N], len;

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(c, 0, sizeof(c)); len = 0;
		for(int i = 1; i <= n; i++)
		{
			int l = 1, r = len;
			while(l <= r)
			{
				int m = l + (r - l) / 2;
				if(a[i] > c[m]) l = m + 1;
				else r = m - 1;
			}
			c[l] = a[i]; L[i] = l;
			if(l > len) len = l;
		}
		memset(c, 0, sizeof(c)); len = 0;
		for(int i = n; i >= 1; i--)
		{
			int l = 1, r = len;
			while(l <= r)
			{
				int m = l + (r - l) / 2;
				if(a[i] > c[m]) l = m + 1;
				else r = m - 1;
			}
			c[l] = a[i]; R[i] = l;
			if(l > len) len = l;
		}
		//for(int i = 1; i <= n; i++) printf("%d ", L[i]); puts("");
		//for(int i = 1; i <= n; i++) printf("%d ", R[i]); puts("");
		int res = 0;
		for(int i = 1; i <= n; i++) 
		{
			int tmp = L[i];
			if(R[i] < tmp) tmp = R[i];
			if(res < tmp * 2 - 1) res = tmp * 2 - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
