#include <cstdio>
#include <cstring>

char sa[100], sb[100];
int ya = -1, yb = -1, ma, mb, da, db;
int n;
char now[100];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", now);
		int y, m, d;
		scanf("%d%d%d", &d, &m, &y);
		if(i == 1)
		{
			strcpy(sa, now);
			strcpy(sb, now);
			ya = yb = y;
			ma = mb = m;
			da = db = d;
		}
		else{
			if(y > ya || (y == ya && m > ma) || (y == ya && m == ma && d > da))
			{
				strcpy(sa, now);
				ya = y; ma = m; da = d;
			}
			if(y < yb || (y == yb && m < mb) || (y == ya && m == mb && d < db))
			{
				strcpy(sb, now);
				yb = y; mb = m; db = d;
			}
		}
	}
	puts(sa); puts(sb);
	return 0;
}
