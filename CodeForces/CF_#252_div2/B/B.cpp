#include <cstdio>
#include <algorithm>

int n, v;
int fruit[3010], left[3010];
int maxday;

int main()
{
	scanf("%d%d", &n, &v);
	for(int i = 1; i <= n; i++)
	{
		int day, num; scanf("%d%d", &day, &num);
		fruit[day] += num;
		if(day > maxday) maxday = day;
	}
	int ans = 0;
	for(int i = 1; i <= maxday+2; i++)
	{
		if(fruit[i] + left[i] <= v) ans += fruit[i] + left[i];
		else{
			ans += v;
			if(left[i] >= v) left[i+1] = fruit[i];
			else left[i+1] = left[i] + fruit[i] - v;
		}
	}
	printf("%d\n", ans);
	return 0;
}
