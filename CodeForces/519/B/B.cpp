#include <cstdio>
#include <map>
#include <algorithm>
using std::map;

const int N = 100000 + 10;

int n, a[N], b[N], c[N];
map<int, int> cnt;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &b[i]);
		cnt[b[i]]--;
	}
	for(int i = 1; i <= n; i++) if(cnt[a[i]])
	{
		printf("%d\n", a[i]);
		break;
	}
	cnt.clear();
	for(int i = 2; i <= n; i++)
		cnt[b[i]]++;
	for(int i = 3; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]--;
	}
	for(int i = 2; i <= n; i++) if(cnt[b[i]])
	{
		printf("%d\n", b[i]);
		break;
	}
	return 0;
}
