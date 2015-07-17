#include <cstdio>

int n, m, L, R;
int ti[10010];
int c[110], d[110];

int main()
{
	scanf("%d%d%d%d", &n, &m, &L, &R);
	for(int i = 1; i <= n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		for(int j = x; j <= y; j++) ti[j] = 1;
	}
	for(int i = 1; i <= m; i++) scanf("%d%d", &c[i], &d[i]);
	int res = 0;
	for(int C = L; C <= R; C++)
	{
		bool flag = 0;
		for(int i = 1; i <= m; i++)
		{
			for(int j = c[i] + C; j <= d[i] + C; j++)
				if(ti[j])
				{
					flag = 1;
					break;
				}
			if(flag) break;
		}
		res += flag;
		//printf("%d ", C);
		//if(flag) printf("is ok");
		//puts("");
	}
	printf("%d\n", res);
	return 0;
}
