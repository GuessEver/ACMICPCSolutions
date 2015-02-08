#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using std::map;

const int N = 100000000 + 10;
const int M = 100000 + 10;

int n, q;
struct COMMAND{ int op, x; }op[M];
int L[M*4], cor[M], maxidx;
map<int, int> hash;
int num[M*16];

void update(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		num[p] += c;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) update(p*2, l, m, a, c);
	else update(p*2+1, m+1, r, a, c);
	num[p] = num[p*2] + num[p*2+1];
}
int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return num[p];
	int m = (l + r) / 2, x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return x1 + x2;
}
int rank(int p, int l, int r, int a)
{
	if(l == r) return L[l] + a - 1;
	int m = (l + r) / 2;
	if(a <= num[p*2]) return rank(p*2, l, m, a);
	else return rank(p*2+1, m+1, r, a-num[p*2]);
}

int main()
{
	//freopen("F.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= q; i++)
		{
			char tmp[10]; int x, t;
			scanf("%s%d", tmp, &x);
			if(tmp[0] == 'T') t = 1;
			else if(tmp[0] == 'R') t = 2;
			else t = 3;
			op[i].op = t; op[i].x = x;
			cor[i] = x;
		}
		hash.clear(); maxidx = 0;
		memset(L, 0, sizeof(L));
		std::sort(cor+1, cor+1+q);
		int len = std::unique(cor+1, cor+1+q) - cor;
		for(int i = 1; i < len; i++)
		{
			if(cor[i] - cor[i-1] > 1)
			{
				L[++maxidx] = cor[i-1] + 1;
				hash[L[maxidx]] = maxidx;
			}
			hash[cor[i]] = ++maxidx;
			L[maxidx] = cor[i];
		}
		if(L[maxidx] < n)
		{
			L[maxidx+1] = L[maxidx] + 1;
			++maxidx;
			hash[L[maxidx]] = maxidx;
		}
		//for(int i = 1; i <= maxidx; i++)printf("%d %d\n", L[i], hash[L[i]]); puts("===");
		L[maxidx+1] = n+1;
		memset(num, 0, sizeof(num));
		//printf("maxidx = %d\n", maxidx);
		int qq = std::max(maxidx, 2 * q + 1);
		for(int i = 1; i <= maxidx; i++)
		{
			//printf("now i = %d ..................................\n", i);
			//printf("%d left = %d, len = %d\n", i+qq, L[i], L[i+1] - L[i]);
			update(1, 1, 2*qq, i+qq, L[i+1] - L[i]);
			//for(int p = 1; p <= 15; p++) printf("%d ", num[p]); puts("");
		}
		for(int i = 1; i <= maxidx; i++)
		{
			hash[L[i]] += qq;
			L[i + qq] = L[i];
			L[i] = 0;
		}
		int topcnt = 0;
		printf("Case %d:\n", cas);
		for(int i = 1; i <= q; i++)
		{
			if(op[i].op == 1) // Top
			{
				update(1, 1, 2 * qq, hash[op[i].x], -1);
				hash[op[i].x] = qq - (++topcnt);
				L[hash[op[i].x]] = op[i].x;
				update(1, 1, 2 * qq, hash[op[i].x], 1);
			}
			else if(op[i].op == 2) // Rank
			{
				printf("%d\n", rank(1, 1, 2 * qq, op[i].x));
			}
			else{ // Query
				printf("%d\n", query(1, 1, 2 * qq, 1, hash[op[i].x]));
			}
		}
	}
	return 0;
}
