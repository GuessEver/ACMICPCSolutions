#include <cstdio>
#include <utility>
using std::pair;
const int N = 100000 + 10;
const int mod1 = 1000000000 + 7;
const int mod2 = 1000000000 + 9;
const int B = 102929;
int n, m, k;
int mulB1[N], mulB2[N], sumB1[N], sumB2[N];
int val[N*4];
typedef pair<int, int> pir;
pir hash[N*4];

void calc(int p, int l, int r, int c)
{
	hash[p].first = 1ll * c * sumB1[r-l] % mod1;
	hash[p].second = 1ll * c * sumB2[r-l] % mod2;
}
void pushDown(int p, int l, int mid, int r)
{
	if(val[p])
	{
		val[p*2] = val[p]; calc(p*2, l, mid, val[p]);
		val[p*2+1] = val[p]; calc(p*2+1, mid+1, r, val[p]);
		val[p] = 0;
	}
}
void change(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		val[p] = c;
		calc(p, l, r, c);
		return;
	}
	int mid = l + (r - l) / 2;
	pushDown(p, l, mid, r);
	if(a <= mid) change(p*2, l, mid, a, b, c);
	if(b > mid) change(p*2+1, mid+1, r, a, b, c);
	hash[p].first = (1ll * hash[p*2].first * mulB1[r-mid] + hash[p*2+1].first) % mod1;
	hash[p].second = (1ll * hash[p*2].second * mulB2[r-mid] + hash[p*2+1].second) % mod2;
}
pir query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return hash[p];
	int mid = l + (r - l) / 2;
	pushDown(p, l, mid, r);
	if(b <= mid) return query(p*2, l, mid, a, b);
	else if(a > mid) return query(p*2+1, mid+1, r, a, b);
	else {
		pir res1 = query(p*2, l, mid, a, mid);
		pir res2 = query(p*2+1, mid+1, r, mid+1, b);
		int first = (1ll * res1.first * mulB1[b-mid] + res2.first) % mod1;
		int second = (1ll * res1.second * mulB2[b-mid] + res2.second) % mod2;
		return std::make_pair(first, second);
	}
}

bool check(int l, int r, int d)
{
	if(r - l + 1 <= d) return 1;
	if(r - l + 1 <= 2 * d)
		return query(1, 1, n, l, l + (r - (l + d) + 1) - 1)
			== query(1, 1, n, l + d, r);
	int len = (r - l + 1) % d; if(len == 0) len = d;
	pir tmp1 = query(1, 1, n, l + d, r - len);
	pir tmp2 = query(1, 1, n, l, r - len - d);
	pir tmp3 = query(1, 1, n, l, l + len - 1);
	pir tmp4 = query(1, 1, n, r - len + 1, r);
	return tmp1 == tmp2 && tmp3 == tmp4;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	mulB1[0] = mulB2[0] = sumB1[0] = sumB2[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		mulB1[i] = 1ll * mulB1[i-1] * B % mod1;
		mulB2[i] = 1ll * mulB2[i-1] * B % mod2;
		sumB1[i] = (0ll + sumB1[i-1] + mulB1[i]) % mod1;
		sumB2[i] = (0ll + sumB2[i-1] + mulB2[i]) % mod2;
	}
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%1d", &x);
		change(1, 1, n, i, i, x + '0');
	}
	for(int i = 1; i <= m + k; i++)
	{
		int op, l, r, d; scanf("%d%d%d%d", &op, &l, &r, &d);
		if(op == 1) change(1, 1, n, l, r, d + '0');
		else puts(check(l, r, d) ? "YES" : "NO");
	}
	return 0;
}
