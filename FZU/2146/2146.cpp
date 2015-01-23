#include <cstdio>
#include <cstring>

char s[20086];

void solve()
{
	memset(s, 0, sizeof(s)); 
	scanf("%s", s);
	int len = strlen(s);
	if(len & 1) printf("Odd\n");
	else printf("Even\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		printf("Case %d: ", i);
		solve();
	}
	return 0;
}
