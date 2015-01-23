#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, m;
struct Node{int a, b, ansa, ansb, o;}game[N], peo[N];

bool cmpa(Node a, Node b) { return a.a < b.a; }
bool cmpb(Node a, Node b) { return a.b < b.b; }
bool cmp(Node a, Node b) { return a.o < b.o; }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &peo[i].a);
	for(int i = 1; i <= n; i++) scanf("%d", &peo[i].b);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", &game[i].a);
	for(int i = 1; i <= m; i++) scanf("%d", &game[i].b);
	for(int i = 1; i <= m; i++)
	{
		game[i].o = i;
		game[i].ansa = game[i].ansb = 0x3f3f3f3f;
	}
	std::sort(game+1, game+1+m, cmpa);
	int j = 1;
	for(int i = 1; i <= m; i++)
	{
		while(game[i].a >= peo[j].a && j <= n) j++;
		if(j <= n) game[i].ansa = j;
	}
	std::sort(game+1, game+1+m, cmpb);
	j = 1;
	for(int i = 1; i <= m; i++)
	{
		while(game[i].b >= peo[j].b && j <= n) j++;
		if(j <= n) game[i].ansb = j;
	}
	std::sort(game+1, game+1+m, cmp);
	for(int i = 1; i <= m; i++)
	{
		//printf("%d %d\n", game[i].ansa, game[i].ansb);
		if(game[i].ansa == game[i].ansb) puts("Draw");
		else if(game[i].ansa > game[i].ansb) puts("Constantine");
		else puts("Mike");
	}

	return 0;
}
