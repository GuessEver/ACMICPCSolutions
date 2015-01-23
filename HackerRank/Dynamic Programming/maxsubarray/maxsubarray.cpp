#include <cstdio>

int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int max = -99999999, x, tmp = 0;
		int flag = 0, sum = 0, maxtmp = -99999999;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if(x > 0) { flag = 1; sum += x; }
			if(x > maxtmp) maxtmp = x;
			tmp += x;
			if(tmp > max) max = tmp;
			if(tmp < 0) tmp = 0;
		}
		if(flag) printf("%d %d\n", max, sum);
		else printf("%d %d\n", max, maxtmp);
	}
	return 0;
}
