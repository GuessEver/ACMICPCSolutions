#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10;

long long tot;
int n;
long long a[N];

int main()
{
	while(scanf("%lld", &tot) == 1)
	{
		tot = tot * 10000000LL;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		std::sort(a+1, a+1+n);
		int i = 1, j = n;
		bool flag = 0;
		while(i < j)
		{
			while(i < j && a[i] + a[j] > tot) j--;
			if(i < j && a[i] + a[j] == tot)
			{
				printf("yes %lld %lld\n", a[i], a[j]);
				flag = 1;
				break;
			}
			else i++;
		}
		if(!flag) puts("danger");
	}
	return 0;
}
