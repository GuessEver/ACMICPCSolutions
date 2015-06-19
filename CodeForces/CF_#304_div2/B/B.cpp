#include <cstdio>

const int N = 3000 + 10;

int n;
int cnt[2*N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	int res = 0;
	for(int i = 1; i <= 2 * n; i++) if(cnt[i] > 1)
	{
		int tmp = cnt[i] - 1;
		cnt[i+1] += tmp;
		res += tmp;
	}
	printf("%d\n", res);
}
