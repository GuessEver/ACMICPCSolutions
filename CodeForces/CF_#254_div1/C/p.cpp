#include <cstdio>
#include <cstdlib>

const int N = 100000 + 10;

int col[N], val[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) col[i] = i;
	while(m--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
		{
			int z; scanf("%d", &z);
			for(int i = x; i <= y; i++)
			{
				val[i] += abs(col[i] - z);
				col[i] = z;
			}
		}
		else{
			long long res = 0;
			for(int i = x; i <= y; i++)
				res += val[i];
			printf("%lld\n", res);
		}
	}
	return 0;
}
