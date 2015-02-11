#include <cstdio>
#include <algorithm>

const int N = 20000 + 10;

struct Node{
	int w, h;
	void Read() { scanf("%d%d", &w, &h); }
	bool operator < (const Node &b) const
	{
		if(w == b.w) return h > b.h;
		return w < b.w;
	}
}a[N];
int n, c[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) a[i].Read();
		std::sort(a+1, a+1+n);
		int len = 0;
		for(int i = 1; i <= n; i++)
		{
			int l = 1, r = len;
			while(l <= r)
			{
				int mid = (l + r) / 2;
				if(a[i].h <= c[mid]) l = mid + 1;
				else r = mid - 1;
			}
			c[l] = a[i].h;
			if(l > len) len = l;
		}
		printf("%d\n", len);
	}
	return 0;
}
