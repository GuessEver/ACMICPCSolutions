#include <cstdio>

int n, a[200][200];
bool h[200];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int x; scanf("%d", &x);
			if(x == 1) h[i] = 1;
			if(x == 2) h[j] = 1;
			if(x == 3) h[i] = h[j] = 1;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(!h[i]) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= n; i++) if(!h[i]) printf("%d ", i);
	return 0;
}
