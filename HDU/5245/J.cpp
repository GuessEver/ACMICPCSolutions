#include <stdio.h>

using namespace std;
int m,n,k;
inline double get(int x, int y)
{
		return 1.0*(2.0*x*(n - x + 1) - 1.0) * ( 2.0 * y * (m - y + 1) - 1.0);
}
double tot;
inline double getAns(int x, int y)
{
		double q = get(x, y)/tot;
		q = 1.0 - q;
		double ans = 1.0;
		for(int i = 0; i < k; i++)
			ans *= q;
		return 1.0 - ans;
}

int main()
{
		int T;
		scanf("%d", &T);
		for(int cas = 1; cas <= T; cas++)
		{
				scanf("%d%d%d", &m, &n, &k);
				double ans = 0.0;
				tot = 1.0*m*n *m *n;
				for(int i = 1; i <= n; i++)
						for(int j = 1; j <= m; j++)
						{
							ans += getAns(i, j);
						}
				printf("Case #%d: %.0f\n",cas, ans);
		}
		return 0;
}
