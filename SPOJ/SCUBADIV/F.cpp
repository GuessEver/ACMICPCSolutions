#include <cstdio>
#include <cstring>
#include <algorithm>

int n, t, a;
int f[100][100];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(f, 0x3f, sizeof(f));
		f[0][0] = 0;
		scanf("%d%d%d", &t, &a, &n);
		for(int i = 1; i <= n; i++)
		{
			int ti, ai, wi;
			scanf("%d%d%d", &ti, &ai, &wi);
			for(int j = t; j >= 0; j--)
				for(int k = a; k >= 0; k--)
				{
					int nj = j + ti;
					if(nj > t) nj = t;
					int nk = k + ai;
					if(nk > a) nk = a;
					if(f[nj][nk] > f[j][k] + wi)
						f[nj][nk] = f[j][k] + wi;
				}
		}
		printf("%d\n", f[t][a]);
	}
	return 0;
}
