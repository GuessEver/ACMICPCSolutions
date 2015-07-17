#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 50000 + 10;
long long val[N];
int n, m;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) val[i] = 1;
		while(m--)
		{
			int op, x, y, p;
			scanf("%d%d%d%d", &op, &x, &y, &p);
			if(op == 0)
			{
				long long res = 1;
				for(int i = x; i <= y; i++) res = res * val[i] % p;
				printf("%lld\n", res);
			}
			else if(op == 1)
			{
				for(int i = x; i <= y; i++) val[i] *= p;
			}
			else{
				for(int i = x; i <= y; i++) val[i] /= p;
			}
		}
	}
	return 0;
}
