#include <cstdio>
#include <cstring>

const int N = 100 + 10;

int n, W;
int cmax;
struct Node{
	int c, p, w, t;
	bool operator < (const Node &b) const
	{
		return w > b.w;
	}
}a[N];
bool used[N];

int ceil(int x, int y) // x / y
{
	if(x % y == 0) return x / y;
	else return x / y + 1;
}
int getWidth(int t, int p)
{
	return ceil(9 * t * p, 16);
}
int getP(int c)
{
	return 8 + ceil(40 * (c - 4), cmax - 4);
}

char tmp[1000];

int main()
{
	int cas = 0;
	while(scanf("%d%d", &W, &n) == 2 && n)
	{
		cmax = -1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s%d", tmp, &a[i].c);
			a[i].t = strlen(tmp);
			if(cmax == -1 || a[i].c > cmax) cmax = a[i].c;
		}
		for(int i = 1; i <= n; i++)
		{
			a[i].p = getP(a[i].c);
			a[i].w = getWidth(a[i].t, a[i].p);
		//	printf("%d %d\n", a[i].p, a[i].w);
		}
		memset(used, 0, sizeof(used));
		int now = 0, res = 0, maxp = 0;
		bool newline = 1;
		for(int i = 1; i <= n; i++)
		{
			if(newline)
			{
				now = a[i].w;
				res += maxp;
				maxp = a[i].p;
				newline = 0;
				continue;
			}
			if(now + a[i].w + 10 <= W)
			{
				now += a[i].w + 10;
				if(a[i].p > maxp) maxp = a[i].p;
			}
			else{
				newline = 1;
				i--;
			}
		}
		printf("CLOUD %d: %d\n", ++cas, res + maxp);
	}
	return 0;
}
