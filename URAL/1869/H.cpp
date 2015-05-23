#include <cstdio>

int n, a[110][110];
bool v[110][110];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	int maxp = 0, now = 0;
	for(int station = 1; station <= n; station++)
	{
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++) // i -> j
			{
				if(!v[i][j] && i <= station && j > station)
				{
					v[i][j] = 1;
					now += a[i][j];
				}
				if(v[i][j] && !(i <= station && j > station))
				{
					v[i][j] = 0;
					now -= a[i][j];
				}
			}
		//printf("%d %d\n", now, maxp);
		if(now > maxp) maxp = now;
	}
	//////////now = maxp = 0;
	for(int station = n; station >= 1; station--)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j < i; j++) // i <- j
			{
				if(!v[i][j] && j < station && i >= station)
				{
					v[i][j] = 1;
					now += a[i][j];
				}
				if(v[i][j] && !(j < station && i >= station))
				{
					v[i][j] = 0;
					now -= a[i][j];
				}
			}
		//printf("%d %d\n", now, maxp);
		if(now > maxp) maxp = now;
	}
	printf("%d\n", (maxp + 35) / 36);
}
