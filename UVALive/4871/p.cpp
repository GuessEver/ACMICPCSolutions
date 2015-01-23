#include <cstdio>
#include <algorithm>

int n, a[1010];

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			for(int k = j + 1; k <= n; k++)
				if(a[i] < a[j] && a[j] < a[k]) return 0;
	return 1;
}

int main()
{
	//while(scanf("%d", &n) == 1 && n)
	for(n = 1; n <= 11; n++)
	{
	//	printf("%d : ", n);
		for(int i = 1; i <= n; i++) a[i] = i;
		long long res = 0;
		do{
			if(check())
			{
				res++;
	//			for(int j = 1; j <= n; j++) printf("%d ", a[j]);
	//			puts("");
			}
		}while(std::next_permutation(a+1, a+1+n));
		printf("%lld\n", res);
	}
	return 0;
}
