#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N], b[N], c[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	std::sort(b+1, b+1+n);
	int k = -1, kk = -1;
	for(int i = 1; i <= n; i++)
		if(a[i] != b[i] && k == -1)
		{
			k = i;
			break;
		}
	for(int i = n; i >= 1; i--)
		if(a[i] != b[i] && kk == -1)
		{
			kk = i;
			break;
		}
	if(k == -1) k = kk = 1;
	int cnt = 0;
	for(int i = 1; i < k; i++) c[++cnt] = a[i];
	for(int i = kk; i >= k; i--) c[++cnt] = a[i];
	for(int i = kk+1; i <= n; i++) c[++cnt] = a[i];
	bool flag = 1;
	for(int i = 1; i <= n; i++)
		if(c[i] != b[i]) flag = 0;
	if(!flag) printf("no\n");
	else printf("yes\n%d %d\n", k, kk);
	return 0;
}
