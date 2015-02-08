#include <cstdio>

const int N = 100000 + 10;

struct Node{
	int x, y;
	bool operator < (const Node &b) const
	{
		return x < b.x && y < b.y;
	}
}a[N];
int n;
int f[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j] < a[i] && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
	}
	int res = 1;
	for(int i = 1; i <= n; i++)
		if(f[i] > res) res = f[i];
	printf("%d\n", res);
	return 0;
}
