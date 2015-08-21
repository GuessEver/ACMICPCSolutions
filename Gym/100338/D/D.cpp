#include <cstdio>

int a, b, c;
int main()
{
	//freopen("nim.in", "r", stdin);
	//freopen("nim.out", "w", stdout);
	while(scanf("%d%d%d", &a, &b, &c) == 3 && (a || b || c))
	{
		if((a + 1) ^ (b + 1) ^ (c + 1)) puts("Alice wins the game.");
		else puts("Bob wins the game.");
	}
	return 0;
}
