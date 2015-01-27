#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10;

struct Node{
	long long price;
	int date;
	bool operator < (const Node &b) const
	{
		if(price == b.price) return date < b.date;
		return price < b.price;
	}
}a[N];
int n, k1, k2;
int ans1[200], ans2[200];

bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

int main()
{
	int cas = 0;
	while(scanf("%d%d%d", &n, &k1, &k2) == 3 && (n || k1 || k2))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i].price);
			a[i].date = i;
		}
		std::sort(a+1, a+1+n);
		printf("Case %d\n", ++cas);
		for(int i = 1; i <= k1; i++) ans1[i] = a[i].date;
		int cnt = 0;
		for(int i = n; i >= (n-k2+1); i--) ans2[++cnt] = a[i].date;
		std::sort(ans1+1, ans1+1+k1, cmp1);
		std::sort(ans2+1, ans2+1+k2, cmp2);
		for(int i = 1; i < k1; i++) printf("%d ", ans1[i]);
		printf("%d\n", ans1[k1]);
		for(int i = 1; i < k2; i++) printf("%d ", ans2[i]);
		printf("%d\n", ans2[k2]);
	}
	return 0;
}
