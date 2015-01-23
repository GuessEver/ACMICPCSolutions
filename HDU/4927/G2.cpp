#include <cstdio>
#include <cstring>

int n;
long long a[3000+10][3000+10];


int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[0][i]);
		int m = n;
		for(int i = 1; i < n; i++)
		{
			for(int j = 1;  j < m; j++)
			{
				a[i][j] = a[i-1][j+1] - a[i-1][j];
			}
			m--;
		}
		printf("%lld\n", a[n-1][1]);
	}
	return 0;
}
