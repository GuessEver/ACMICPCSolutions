#include <cstdio>

struct Status{
	int op, dir, mood;
	void Read()
	{
		char tmp, mo;
		scanf("%d%c%c", &op, &tmp, &mo);
		dir = (tmp == 'R') ? 1 : -1;
		if(mo == 'H') mood = 6;
		else mood = mo - 'A' + 1;
	}
}r[10][5];//r[mood][nice/ugly]
bool tree[200000010];

int main()
{
	freopen("beavers.in", "r", stdin);
	//freopen("beavers.out", "w", stdout);
	for(int i = 1; i <= 5; i++)
		for(int j = 0; j <= 1; j++)
			r[i][j].Read();
	int i = 100000000, mo = 1, cnt = 0;
	while(++cnt <= 100000000)
	{
	//	printf("idx = %d, mood = %d, tree[i] = %d", i, mo, tree[i]);
		Status now = r[mo][tree[i]];
		tree[i] = now.op;
	//	printf(" --> %d\n", tree[i]);
		mo = now.mood;
		i += now.dir;
		if(mo == 6)
		{
			puts("happy beaver");
			return 0;
		}
	}
	puts("unhappy beaver");
	return 0;
}
