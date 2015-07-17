#include <cstdio>
#include <algorithm>
using std::max;

int n, a[100000+10];
int l[100010], r[100010];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[n+1] = 2000000000;
	for(int i = 1; i <= n; i++)
		if(a[i] > a[i-1]) l[i] = l[i-1] + 1;
		else l[i] = 1;
	for(int i = n; i >= 1; i--)
		if(a[i] < a[i+1]) r[i] = r[i+1] + 1;
		else r[i] = 1;
	//for(int i = 1; i <= n; i++) printf("%d ", l[i]);puts("");
	//for(int i = 1; i <= n; i++) printf("%d ", r[i]);puts("");
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i+1] > a[i-1]+1) res = max(res, l[i-1] + r[i+1] + 1);
		//printf("%d\n", res);
	}
	for(int i = 1; i < n; i++)
		res = max(res, r[i+1] + 1);
	for(int i = 2; i <= n; i++)
		res = max(res, l[i-1] + 1);
	printf("%d\n", res);
	return 0;
}
