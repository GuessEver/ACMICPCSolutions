#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10;

int n;
struct Node{
	int s, b, idx;
	void Read(int i) 
	{
		scanf("%d%d", &s, &b);
		idx = i;
	}
	bool operator < (const Node &k) const
	{
		if(s == k.s) return b > k.b;
		return s < k.s;
	}
}p[N];
int c[N], f[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		p[i].Read(i);
	std::sort(p+1, p+1+n);
	int len = 0;
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = len;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(p[i].b > c[mid]) l = mid + 1;
			else r = mid - 1;
		}
		c[l] = p[i].b;
		if(l > len) len = l;
		f[i] = l;
	}
	//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
	printf("%d\n", len);
	for(int i = n; i >= 1; i--)
		if(f[i] == len)
		{
			printf("%d%s", p[i].idx, len == 1 ? "\n" : " ");
			len--;
		}
	return 0;
}
