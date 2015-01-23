#include <cstdio>
#include <algorithm>
using std::max;

const int N = 6000 + 10;

int n, a[N], root, in[N];
struct Link{int y; Link *next;}*head[N];
int f[N][2];
bool calced[N][2];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

int calc(int x, bool join)
{
	if(calced[x][join]) return f[x][join];
	calced[x][join] = 1;
	int t1 = 0, t2 = 0;
	for(Link *p = head[x]; p; p = p->next)
	{
		if(join) t1 += calc(p->y, !join);
		else{
			t2 += max(calc(p->y, join), calc(p->y, !join));
		}
	}
	f[x][join] = max(t1, t2);
	if(join) f[x][join] += a[x];
	return f[x][join];
}

int main()
{
	freopen("1052.in", "r", stdin);
	freopen("1052.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++)
	{
		int x, y; scanf("%d%d", &y, &x);
		inLink(x, y);
		in[y]++;
	}
	for(int i = 1; i <= n; i++) if(!in[i]) root = i;
	int res = max(calc(root, 0), calc(root, 1));
	printf("%d\n", res);
	return 0;
}
