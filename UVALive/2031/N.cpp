#include <cstdio>
#include <cstring>
#include <algorithm>

int f[2][5][5];
int v[5][5];

int main()
{
	int x;
	for(int a = 1; a <= 4; a++) v[0][a] = 2;
	v[1][2] = v[1][4] = v[2][1] = v[2][3] = v[3][2] = v[3][4] = v[4][1] = v[4][3] = 3;
	v[1][3] = v[2][4] = v[3][1] = v[4][2] = 4;
	for(int a = 1; a <= 4; a++) v[a][a] = 1;
	while(scanf("%d", &x) && x)
	{
		memset(f, 0x3f, sizeof(f));
		f[0][0][0] = 0;
		do{
			for(int a = 0; a <= 4; a++)
				for(int b = 0; b <= 4; b++)
				{
					f[1][x][b] = std::min(f[1][x][b], f[0][a][b] + v[a][x]);
					f[1][a][x] = std::min(f[1][a][x], f[0][a][b] + v[b][x]);
				}
			for(int a = 0; a <= 4; a++)
				for(int b = 0; b <= 4; b++) f[0][a][b] = f[1][a][b];
			memset(f[1], 0x3f, sizeof(f[1]));
		}while(scanf("%d", &x) && x);
		int res = 0x3f3f3f3f;
		for(int a = 0; a <= 4; a++)
			for(int b = 0; b <= 4; b++)
				res = std::min(res, f[0][a][b]);
		printf("%d\n", res);
	}
	return 0;
}
