#include <cstdio>

const int N = 50 + 10;

int n, m;
struct EG{int x, y;}edge[N * N];
int Cnt;
int f[N];

void read()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[Cnt++] = (EG){a, b};
	}
}

int getroot(int a) { return f[a] == a ? a : f[a] = getroot(f[a]); }

int kruskal()
{
	int sum = 0;
	for(int i = 0; i < Cnt; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		f[getroot(edge[i].x)] = getroot(edge[i].y);
		sum++;
	}
	return sum;
}

void solve()
{
	for(int i = 1; i <= n+1; i++) f[i] = i;
	int mul = kruskal();
	//printf("%d\n", mul);
	long long res = 1;
	for(int i = 1; i <= mul; i++) res *= 2;
	printf("%I64d\n", res);
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	read();
	solve();
	return 0;
}
