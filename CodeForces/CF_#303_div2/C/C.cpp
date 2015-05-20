#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n;
struct Node{
	int x, h;
}v[N];

int main()
{
	scanf("%d", &n);
	if(n == 1) { puts("1"); return 0; }
	for(int i = 1; i <= n; i++) scanf("%d%d", &v[i].x, &v[i].h);
	int res = 2, pre = v[1].x;
	for(int i = 2; i < n; i++)
	{
		if(v[i].x - v[i].h > pre)
		{
			res++;
			pre = v[i].x;
		}
		else if(v[i].x + v[i].h < v[i+1].x)
		{
			res++;
			pre = v[i].x + v[i].h;
		}
		else pre = v[i].x;
	}
	printf("%d\n", res);
	return 0;
}
