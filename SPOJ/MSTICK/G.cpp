#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 5000 + 10;

struct Node{
	int a, b;
	void Read() { scanf("%d%d", &a, &b); }
	bool operator < (const Node &t) const
	{
		if(a == t.a) return b < t.b;
		return a < t.a;
	}
}a[N];
int n, c[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(c, 0, sizeof(c));
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
				if(a[i].b < c[mid]) l = mid + 1;
				else r = mid - 1;
			}
			c[l] = a[i].b;
			if(l > len) len = l;
		}
		printf("%d\n", len);
	}
	return 0;
}
