#include <cstdio>

int a[20];
const int inf = 0x3f3f3f3f;
int n = 15;

void del(int k)
{
	int v[20];
	for(int i = 1; i < k; i++) v[i] = a[i];
	for(int i = k+1; i <= n; i++) v[i-1] = a[i];
	n--;
	for(int i = 1; i <= n; i++) a[i] = v[i];
	a[n+1] = 0;
}

void solve()
{
	n = 15;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	bool flag = 1;
	int res = 0;
	while(flag)
	{
		flag = 0;
		for(int i = 1; i <= n; i++)
		{
			while(a[i] == a[i+1] && a[i] != 0) del(i+1);
			if(a[i] > a[i-1] && a[i] > a[i+1])
			{
				del(i);
				res++;
				flag = 1;
			}
		}
		//for(int i = 1; i<= n; i++) printf("%d ", a[i]);puts("");
	}
	printf("%d\n", res);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		solve();
	}
	return 0;
}
