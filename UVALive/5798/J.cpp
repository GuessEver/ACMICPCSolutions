#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

const int N = 100000 + 10;

long long B, P; 
int n, m;
long long mulb[N];
long long num[N*4];

void change(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		num[p] = c % P;
		return;
	}
	int m = l + (r - l) / 2;
	if(a <= m) change(p*2, l, m, a, c);
	else change(p*2+1, m+1, r, a, c);
	int right = r - (m + 1) + 1;
	num[p] = ((num[p*2] * mulb[right]) % P + num[p*2+1]) % P;
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return num[p] % P;
	int m = l + (r - l) / 2;
	int right = min(r, b) - (m + 1) + 1;
	long long res1 = 0, res2 = 0;
	if(a <= m) res1 = query(p*2, l, m, a, b);
	if(b > m) res2 = query(p*2+1, m+1, r, a, b);
	if(right < 0) right = 0;
	return (res1 * mulb[right] % P + res2) % P;
}

int main()
{
	freopen("J.in", "r", stdin);
	while(scanf("%lld%lld%d%d", &B, &P, &n, &m) == 4 && (B||P||n||m))
	{
		mulb[0] = 1;
		for(int i = 1; i <= n; i++)
			mulb[i] = (mulb[i-1] % P) * (B % P) % P;
		memset(num, 0, sizeof(num));
		while(m--)
		{
			char op[10]; int a, b;
			scanf("%s", op); scanf("%d%d", &a, &b);
			if(op[0] == 'E') change(1, 1, n, a, b);
			else{
				printf("%lld\n", query(1, 1, n, a, b) % P);
			}
		}
		puts("-");
		//for(int i = 1; i <= 10; i++) printf("%d %lld\n", i, num[i]);
	}
	return 0;
}
