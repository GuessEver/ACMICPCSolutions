#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;

int n, l, pos[N];

int main()
{
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++) scanf("%d", &pos[i]);
	std::sort(pos, pos+1+n);
	double res = 0;
	for(int i = 2; i <= n; i++)
		res = std::max(res, (pos[i] - pos[i-1]) / 2.0);
	res = std::max(res, 1.0 * pos[1]);
	res = std::max(res, 1.0 * (l - pos[n]));
	printf("%.10lf\n", res);
	return 0;
}
