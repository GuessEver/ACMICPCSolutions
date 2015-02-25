#include <cstdio>
#include <algorithm>

int n, m, k;
int a[100010], pos[100010];

int solve(int x)
{
	int res = pos[x] / k + 1;
	if(pos[x] == 0) return res;
	int pre = pos[x] - 1;
	pos[x]--; pos[a[pre]]++;
	std::swap(a[pre], a[pre+1]);
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	long long res = 0;
	while(m--)
	{
		int x; scanf("%d", &x);
		res += solve(x);
		//for(int i = 0; i < n; i++) printf("%d ", a[i]); puts("");
	}
	printf("%I64d\n", res);
	return 0;
}
