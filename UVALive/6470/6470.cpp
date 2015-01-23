#include <cstdio>
#include <cstring>

int n;
int a, b, c;
int cal[110][110][110];

bool win(int x, int y, int z)
{
	if(y == 0 && z == 0 && x == 1) return 1;
	if(cal[x][y][z] != -1) return cal[x][y][z];
	bool flag = 1;
	for(int i = 2; i <= x; i++)
	{
		int xx = i-1, yy = y, zz = z;
		if(xx < yy) yy = xx;
		if(xx < zz) zz = xx;
		if(win(xx, yy, zz)) flag = 0;
	}
	for(int i = 1; i <= y; i++)
	{
		int xx = x, yy = i-1, zz = z;
		if(yy < zz) zz = yy;
		if(win(xx, yy, zz)) flag = 0;
	}
	for(int i = 1; i <= z; i++)
	{
		int xx = x, yy = y, zz = i-1;
		if(win(xx, yy, zz)) flag = 0;
	}
	return cal[x][y][z] = flag;
}

void solve()
{
	n = 3;
	scanf("%d%d%d", &a, &b, &c);
	for(int i = 2; i <= a; i++)
	{
		int xx = i-1, yy = b, zz = c;
		if(xx < yy) yy = xx;
		if(xx < zz) zz = xx;
		if(win(xx, yy, zz))
		{
			printf("W %d 1\n", i);
			return;
		}
	}
	for(int i = 1; i <= b; i++)
	{
		int xx = a, yy = i-1, zz = c;
		if(yy < zz) zz = yy;
		if(win(xx, yy, zz))
		{
			printf("W %d 2\n", i);
			return;
		}
	}
	for(int i = 1; i <= c; i++)
	{
		int xx = a, yy = b, zz = i-1;
		if(win(xx, yy, zz))
		{
			printf("W %d 3\n", i);
			return;
		}
	}
	printf("L\n");
}

int main()
{
	memset(cal, -1, sizeof(cal));
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		solve();
	}
	return 0;
}
