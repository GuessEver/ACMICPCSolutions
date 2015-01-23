#include <cstdio>

int x, y, m;
int cap[500][500];

int main()
{
	scanf("%d%d%d", &x, &y, &m);
	while(m--)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for(int i = x1; i <= x2; i++)
			for(int j = y1; j <= y2; j++)
				cap[i][j] = 1;
	}
	int res = 0;
	for(int i = 1; i <= x; i++)
		for(int j = 1; j <= y; j++)
			if(cap[i][j]) res++;
	printf("%d\n", res);
	return 0;
}
