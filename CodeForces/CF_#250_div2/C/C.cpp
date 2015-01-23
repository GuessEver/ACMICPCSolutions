#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;

int n, m;
struct Point{
	int idx, v;
}a[N];
int v[N];
struct Link{ int y; Link *next; }*head[N];
bool hash[N][N];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

bool cmp(Point a, Point b) { return a.v > b.v; }

long long solve(int x)
{
	long long tmp = 0;
	for(Link *p = head[x]; p; p = p -> next) if(!hash[x][p->y])
	{
		hash[x][p->y] = hash[p->y][x] = 1;
		tmp += v[p->y];
	}
	return tmp;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].v);
		a[i].idx = i;
		v[i] = a[i].v;
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		inLink(x, y);
		inLink(y, x);
	}
	std::sort(a+1, a+1+n, cmp);
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		long long tmp = solve(a[i].idx);
		//printf("%d : %I64d\n", a[i].idx, tmp);
		res += tmp;
	}
	printf("%I64d\n", res);
	return 0;
}
