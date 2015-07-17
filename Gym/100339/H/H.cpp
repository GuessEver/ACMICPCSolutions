#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using std::map;

const int N = 10000 + 10;

int sa[N], rank[N];
int c[N], tmp[N];
int height[N];

bool cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void DA(char *s, int n, int m) // s[0...n-1] E [1, m)
{
	int i, j, p, *x = rank, *y = tmp;
	for(i = 0; i < m; i++) c[i] = 0;
	for(i = 0; i < n; i++) c[x[i] = s[i]]++;
	for(i = 1; i < m; i++) c[i] += c[i-1];
	for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
	for(j = 1, p = 0; p < n; j *= 2, m = p)
	{
		for(p = 0, i = n-j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) c[i] = 0;
		for(i = 0; i < n; i++) c[x[y[i]]]++;
		for(i = 1; i < m; i++) c[i] += c[i-1];
		for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		for(std::swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p - 1 : p++;
	}
	for(i = 0; i < n; i++) rank[sa[i]] = i;

	int k = 0; height[0] = 0;
	for(i = 0; i < n; height[rank[i++]] = k) if(rank[i])
		for(k ? k-- : 0, j = sa[rank[i]-1]; s[j+k] == s[i+k]; k++);
}

int n, K;
char s[N];

int main()
{
	freopen("seti.in", "r", stdin);
	//freopen("seti.out", "w", stdout);
	scanf("%s", s); n = strlen(s);
	s[n++] = '$';
	DA(s, n, 'z'+1);
/*	for(int i = 0; i < n; i++)
	{
		printf("rank = %d -> [%d, %d) [%d] :", i, sa[i], n, height[i]);
		puts(s+sa[i]);
	}	*/
	int res = 0;
	for(int len = 1; len <= n / 2; len++)
	{
		int minx = n + 1, maxx = 0;
		for(int i = 1; i < n; i++)
		{
			if(height[i] >= len)
			{
				minx = std::min(minx, sa[i]);
				minx = std::min(minx, sa[i-1]);
				maxx = std::max(maxx, sa[i]);
				maxx = std::max(maxx, sa[i-1]);
				continue;
			}
			else{
				res += (minx + len <= maxx);
				minx = n + 1; maxx = 0;
			}
		}
		res += (minx + len <= maxx);
		//printf("len = %d, res = %d\n", len, res);
	}
	printf("%d\n", res);
	return 0;
}
