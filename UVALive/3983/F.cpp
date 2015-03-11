#include <cstdio>
#include <cstring>
#include <cstdlib>

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
int idx[2*N];
long long val[2*N];

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
		memset(idx, 0, sizeof(idx));
		memset(val, 0, sizeof(val));
		memset(f, 0, sizeof(f));
		int l, r; idx[l = r = 0] = 0; // [l, r]
		for(int i = 1; i <= n; i++)
		{
			while(l <= r && sum[i] - sum[idx[l]] > C) l++;
			int j = idx[l];
			f[i] = back[j + 1] + f[j] + (dis[i] - dis[j + 1]) + back[i];
			int tmp = back[i + 1] + f[i] - dis[i + 1];
			while(r >= l && tmp <= val[r]) r--;
			++r; idx[r] = i; val[r] = tmp;
		}
		//for(int i = 1; i <= n; i++) printf("f[%d] = %lld\n", i, f[i]);
		printf("%lld\n", f[n]);
		if(T) puts("");
	}
	return 0;
}
