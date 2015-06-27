#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int from[N], to[N]; // from -> i -> to
int n, k;
int res = 0;

void takeout(int x)
{
	if(to[x] == -1) return;
	takeout(to[x]);
	from[to[x]] = -1; to[x] = -1; 
	res++;
}

int main()
{
	scanf("%d%d", &n, &k);
	memset(from, -1, sizeof(from));
	memset(to, -1, sizeof(to));
	for(int i = 1; i <= k; i++)
	{
		int num, x; scanf("%d%d", &num, &x);
		for(int j = 2; j <= num; j++)
		{
			int y; scanf("%d", &y);
			from[y] = x; to[x] = y;
			x = y;
		}
	}
	//for(int i = 1; i <= n; i++) printf("%d %d\n", from[i], to[i]);
	for(int i = 1; i < n; i++)
	{
		int tar = i + 1; // i -> tar = to[i]
		if(to[i] != -1 && to[i] != tar)
		{
			res++;
			from[to[i]] = -1;
			to[i] = -1;
		}
		if(from[tar] != -1 && from[tar] != i)
		{
			res++;
			to[from[tar]] = -1;
			from[tar] = -1;
		}
		if(to[i] != tar)
		{
			if(to[tar] != -1) takeout(tar);
			to[i] = tar;
			from[tar] = i;
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
