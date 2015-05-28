#include <cstdio>
#include <set>
using std::set;

const int N = 100000 + 10;

int n, a[N];
set<int> hash;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int q; scanf("%d", &q);
	while(q--)
	{
		int l, r; scanf("%d%d", &l, &r);
		int res = 0;
		for(int i = l; i <= r; i++)
			for(int j = i; j <= r; j++)
			{
				hash.clear(); int sum = 0;
				for(int t = i; t <= j; t++)
				{
					if(hash.find(a[t]) != hash.end()) continue;
					hash.insert(a[t]);
					sum += a[t];
				}
				if(sum > res) res = sum;
			}
		printf("%d\n", res);
	}
	return 0;
}
