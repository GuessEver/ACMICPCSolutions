#include <cstdio>
#include <algorithm>

int a, b, c;
int aa, bb, cc;

void solve()
{
	int tmpabc[3] = {a, b, c};
	std::sort(tmpabc, tmpabc+3);
	a = tmpabc[0]; b = tmpabc[1]; c = tmpabc[2];
	if(a == b && b== c)
	{
		if(a < 13) aa = bb = cc = a + 1;
		return;
	}
	if(a == b)
	{
		if(c < 13)
		{
			aa = bb = a; cc = c + 1;
		}
		else{
			aa = bb = a + 1;
			cc = 1;
		}
		return;
	}
	if(b == c)
	{
		if(a < 13)
		{
			bb = cc = b;
			aa = a + 1;
			if(aa == bb)
			{
				if(aa < 13) aa++;
				else aa = bb = cc = 1;
			}
		}
		return;
	}
	else{
		aa = bb = 1;
		cc = 2;
		return;
	}
}

int main()
{
	while(scanf("%d%d%d", &a, &b, &c) == 3 && (a||b||c))
	{
		aa = bb = cc = -1;
		solve();
		if(aa != -1)
		{
			int tmpabc[3] = {aa, bb, cc};
			std::sort(tmpabc, tmpabc+3);
			printf("%d %d %d\n", tmpabc[0], tmpabc[1], tmpabc[2]);
		}
		else printf("*\n");
	}
	return 0;
}
