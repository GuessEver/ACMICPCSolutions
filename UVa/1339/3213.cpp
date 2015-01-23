#include <cstdio>
#include <cstring>

char a[200], b[200];
char cnt['z' + 10];

bool solve()
{
	int len = strlen(a);
	for(int i = 'A'; i <= 'Z'; ++i)
	{
		int tmp = 0;
		for(int j = 0; j < len; ++j) if(a[j] == i) ++tmp;
		++cnt[tmp]; tmp = 0;
		for(int j = 0; j < len; ++j) if(b[j] == i) ++tmp;
		--cnt[tmp];
	}
	for(int i = 1; i <= 100; ++i) if(cnt[i]) return 0;
	return 1;
}

int main()
{
	freopen("3213.in", "r", stdin);
	freopen("3213.out", "w", stdout);
	while(scanf("%s%s", b, a) == 2)
	{
		if(solve()) printf("YES\n");
		else printf("NO\n");
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}
