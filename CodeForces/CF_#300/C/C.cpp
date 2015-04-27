#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int d[N];
int n, m;
int res = -1;
bool WRONG = 0;

int solve(int j, int i, int hj, int hi) // j .. i
{
	res = std::max(res, std::max(hi, hj));
	while(j + 1 < i)
	{
		if(hj <= hi)
		{
			hj++;
			++j;
		}
		else {
			hi++;
			--i;
		}
		res = std::max(res, std::max(hi, hj));
	}
	if(abs(hi - hj) > 1) WRONG = 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	int pre = 0;
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		d[i] = x;
		if(i == 1) res = std::max(res, d[i] - 1 + y);
		else solve(d[i-1], d[i], pre, y);
		pre = y;
	}
	res = std::max(res, n - std::max(1, d[m]) + pre);
	if(res == -1 || WRONG) puts("IMPOSSIBLE");
	else printf("%d\n", res);
	return 0;
}
