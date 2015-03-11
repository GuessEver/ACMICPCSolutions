#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int N = 100000 + 10;

int C, n;
struct Node{
	int x, y, w;
	void Read()
		{ scanf("%d%d%d", &x, &y, &w); }
}a[N];
long long dis[N], back[N];
int sum[N];
long long f[N];

long long DIS(int i, int j)
{
	return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &C, &n);
		for(int i = 1; i <= n; i++) a[i].Read();
		for(int i = 1; i <= n; i++)
		{
			back[i] = DIS(i, 0);
			dis[i] = dis[i-1] + DIS(i-1, i);
			sum[i] = sum[i-1] + a[i].w;
		}
		memset(f, 0x3f, sizeof(f)); f[0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < i; j++)
				if(sum[i] - sum[j] <= C)
					f[i] = std::min(f[i], f[j] + back[j+1] + (dis[i] - dis[j+1]) + back[i]);
	//	for(int i = 1; i <= n; i++) printf("f[%d] = %lld\n", i, f[i]);
		printf("%lld\n", f[n]);
		if(T) puts("");
	}
	return 0;
}
