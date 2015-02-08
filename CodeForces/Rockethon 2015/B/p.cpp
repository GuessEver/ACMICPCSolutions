#include <cstdio>
#include <algorithm>

int a[10], n, m;
int f[10];

int check()
{
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int minx = a[i];
		for(int j = i; j <= n; j++)
		{
			if(a[j] < minx) minx = a[j];
			res += minx;
		}
	}
	//printf("res = %d\n", res);
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) a[i] = i;
	int maxx = -1, cnt = 0;
	do{
		int cc = check();
		if(maxx == -1 || cc > maxx) maxx = cc;
	}while(std::next_permutation(a+1, a+1+n));
	printf("maxx = %d\n", maxx);
	for(int i = 1; i <= n; i++) a[i] = i;
	do{
		int cc = check();
		if(cc == maxx)
		{
			cnt++;
			for(int i = 1; i < n; i++) printf("%d ", a[i]);
			printf("%d\n", a[n]);
			printf("res = %d\n", cc);
		}
		if(0 && cnt == m)
		{
			for(int i = 1; i < n; i++) printf("%d ", a[i]);
			printf("%d\n", a[n]);
			return 0;
		}
	}while(std::next_permutation(a+1, a+1+n));
	return 0;
}
