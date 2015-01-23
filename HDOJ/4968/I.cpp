#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;

const int down[] = {0, 85, 80, 75, 70, 60};
const int up[] = {0, 100, 84, 79, 74, 69};
const double val[] = {0, 4.0, 3.5, 3.0, 2.5, 2.0};

int a[10], n, tot;
double ans_min, ans_max;

void renew()
{
	int all_min = 0, all_max = 0;
	for(int i = 1; i <= 5; i++)
	{
		all_min += down[i] * a[i];
		all_max += up[i] * a[i];
	}
	if(!(all_min <= tot && tot <= all_max)) return;
	//printf("%d %d %d", tot, all_min, all_max);
	//puts("!!!!!!!!!!!!!");
	double value = 0;
	for(int i = 1; i <= 5; i++)
	{
		value += val[i] * a[i];
	}
	value /= (1.0 * n);
	ans_min = min(ans_min, value);
	ans_max = max(ans_max, value);
}

void dfs(int x, int all)
{
	if(x > 5)
	{
		//for(int i = 1; i <= 5; i++) printf("%d ", a[i]); puts("");
		//printf("----->%.4lf %.4lf\n", ans_min, ans_max);
		renew();
		return;
	}
	if(x != 5)
	{
		for(int i = 0; i <= all; i++)
		{
			a[x] = i;
			dfs(x+1, all-i);
		}
	}
	else {
		a[x] = all;
		dfs(x+1, 0);
	}
}

int main()
{
	//freopen("I.out", "w ", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		ans_min = 1e10;
		ans_max = -1e10;
		scanf("%d%d", &tot, &n);
		tot *= n;
		dfs(1, n);
		printf("%.4lf %.4lf\n", ans_min, ans_max);
		//a[1] = 2; a[2] = 7; a[3] = a[4] = 0; a[5] = 1;
		//renew();
	}
	return 0;
}
