#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int res;
	if(n == 1 || n == 2) res = n;
	else{
		res = 2;
		std::sort(a+1, a+1+n);
		long long sum = a[1] + a[2];
		for(int i = 3; i <= n; i++)
			if(a[i] >= sum)
			{
				sum += a[i];
				res++;
			}
	}
	printf("%d\n", res);
	return 0;
}
