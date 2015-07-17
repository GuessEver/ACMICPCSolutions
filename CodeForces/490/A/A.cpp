#include <cstdio>
#include <algorithm>
using std::min;

struct Node{
	int a, b, c;
}a[5010];
int n, p[5010], hash[5010];
int cnt[4], Cnt = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		cnt[p[i]]++;
	}
	Cnt = min(cnt[1], min(cnt[2], cnt[3]));
	printf("%d\n", Cnt);
	for(int t = 1; t <= Cnt; t++)
	{
		for(int i = 1; i <= n; i++) if(!hash[i])
		{
			if(p[i] == 1 && a[t].a == 0)
			{
				a[t].a = i;
				hash[i] = 1;
			}
			if(p[i] == 2 && a[t].b == 0)
			{
				a[t].b = i;
				hash[i] = 1;
			}
			if(p[i] == 3 && a[t].c == 0)
			{
				a[t].c = i;
				hash[i] = 1;
			}
		}
		printf("%d %d %d\n", a[t].a, a[t].b, a[t].c);
	}
	return 0;
}
