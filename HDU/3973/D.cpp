#include <cstdio>
#include <cstring>
#include <set>
using std::set;

const int N = 100000 + 10;
const int B = 31;

int n;
char str[2000000+10];
set<unsigned long long> l;
unsigned long long val[N*4];
unsigned long long mul[2000000+10];

unsigned long long getHash(char *t)
{
	unsigned long long res = 0;
	for(int i = 0; t[i]; i++)
		res = res * B + t[i] - 'a' + 1;
	return res;
}

void change(int p, int l, int r, int a, char c)
{
	if(l == r && l == a)
	{
		val[p] = c - 'a' + 1;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) change(p*2, l, m, a, c);
	else change(p*2+1, m+1, r, a, c);
	val[p] = val[p*2] * mul[r - m] + val[p*2+1];
}

unsigned long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int m = (l + r) / 2;
	unsigned long long x1 = 0, x2 = 0;
	if(b <= m) return query(p*2, l, m, a, b);
	else if(a > m) return x2 = query(p*2+1, m+1, r, a, b);
	else return query(p*2, l, m, a, m) * mul[b - m] 
		+ query(p*2+1, m+1, r, m+1, b);
}

int main()
{
	//freopen("D.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		l.clear();
		memset(val, 0, sizeof(val));
		printf("Case #%d:\n", cas);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			unsigned long long tmp = getHash(str);
		//		printf("  !!  tmp = %llu\n", tmp);
			l.insert(tmp);
		}
		scanf("%s", str); n = strlen(str);
		mul[0] = 1;
		for(int i = 1; i <= n; i++) mul[i] = mul[i-1] * B;
		for(int i = 0; i < n; i++)
			change(1, 0, n-1, i, str[i]);
		int q; scanf("%d", &q);
		while(q--)
		{
			char op; scanf(" %c", &op);
			if(op == 'Q')
			{
				int x, y; scanf("%d%d", &x, &y);
				unsigned long long tmp = query(1, 0, n-1, x, y);
		//		printf("tmp = %llu\n", tmp);
				if(l.find(tmp) == l.end()) puts("No");
				else puts("Yes");
			}
			else{
				int x; char ch; scanf("%d %c", &x, &ch);
				change(1, 0, n-1, x, ch);
			}
		//	for(int p = 1; p <= 15; p++) printf("%llu ", val[p]); puts("");
		}
	}
	return 0;
}
