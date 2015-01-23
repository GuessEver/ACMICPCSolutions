#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

bool hash[10000][10000];

int main()
{
	srand(time(0));
	int T = 30;
	while(T--)
	{
		memset(hash, 0, sizeof(hash));
		int n = 10, t = 400;
		printf("%d %d\n", n, t);
		while(n--)
		{
			int x, y;
			do{
				x = rand()%10 - rand()%5;
				y = rand()%10 + 1;
			}while(hash[x+1000][y+1000]);
			hash[x+1000][y+1000] = 1;
			int ti = rand()%10 + 10;
			int v = rand()%20 + 1;
			printf("%d %d %d %d\n", x, y, ti, v);
		}
	}
	return 0;
}
