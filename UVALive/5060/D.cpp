#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

const int N = (1 << 15) + 10;

struct Tree{
	int idx, hp;
}tr[N*4];
int initp[N];
int n, rec;
int ans[N], L;

void inTree(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		tr[p].idx = a;
		tr[p].hp = c;
		return;
	}
	int m = l + (r - l) / 2;
	if(a <= m) inTree(p*2, l, m, a, c);
	else inTree(p*2+1, m+1, r, a, c);
	int ls = p * 2, rs = ls + 1;
	if(tr[ls].hp >= tr[rs].hp) // bigger hp OR less idx
	{
		tr[p].idx = tr[ls].idx;
		tr[p].hp = tr[ls].hp - tr[rs].hp;
		tr[p].hp = min(initp[tr[p].idx], tr[p].hp + rec);
	}
	else{
		tr[p].idx = tr[rs].idx;
		tr[p].hp = tr[rs].hp - tr[ls].hp;
		tr[p].hp = min(initp[tr[p].idx], tr[p].hp + rec);
	}
}

void solve()
{
	L = 0;
	int p = 1;
	int winner = tr[1].idx;
	while(1)
	{
		int ls = p * 2, rs = ls + 1;
		if(tr[ls].idx == winner)
		{
			ans[L++] = tr[rs].idx;
			p = ls;
		}
		else if(tr[rs].idx == winner)
		{
			ans[L++] = tr[ls].idx;
			p = rs;
		}
		else break;
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(tr, 0, sizeof(tr));
		scanf("%d%d", &n, &rec);
		n = (1 << n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &initp[i]);
			inTree(1, 1, n, i, initp[i]);
		}
		//for(int i = 1; i <= 16; i++)
		//	printf("%d : (%d) = %d\n", i, tr[i].idx, tr[i].hp);
		//puts("====================");
		solve();
		printf("%d\n", tr[1].idx);
		for(int i = L - 1; i > 0; i--) printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
	return 0;
}
