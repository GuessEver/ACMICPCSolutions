#include <cstdio>
#include <map>
#include <algorithm>
using std::map;

int m, t, r;
int w[310];
map<int, int> burn, light;

int main()
{
	scanf("%d%d%d", &m, &t, &r);
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	std::sort(w+1, w+1+m);
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int y = 1; y <= r; y++)
		{
			if(burn[w[i]] >= r) break;
			int j = w[i] - 1;
			while(light[j] == 1) j--;
			light[j] = 1;
			for(int k = j + 1; k <= j + t; k++) burn[k]++;
			cnt++;
		}
		if(burn[w[i]] < r)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
