#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N], b[N];
int cnta, cntb;

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		cnta = cntb = 0;
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			if(i % 2) a[++cnta] = x;
			else b[++cntb] = x;
		}
		std::sort(a+1, a+1+cnta);
		std::sort(b+1, b+1+cntb);
		int maxp = std::max(cnta, cntb);
		if(cntb == cnta - 1) b[++cntb] = 101;
		bool flag = 1;
		for(int i = 1; i <= maxp; i++)
			if(a[i] > b[i])
			{
				flag = 0;
				break;
			}
		if(flag) puts("Yes"); else puts("No");
	}
	return 0;
}
