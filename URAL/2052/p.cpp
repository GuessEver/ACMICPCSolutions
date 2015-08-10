#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10;

int n, a[N];

bool cmp(int a, int b)
{
	int x = a, y = b, xx = 0, yy = 0;
	while(x) { xx += x % 10; x /= 10; }
	while(y) { yy += y % 10; y /= 10; }
	return (xx < yy) || (xx == yy && a < b);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) a[i] = i;
	std::sort(a+1, a+1+n, cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == i)
		{
			cnt++;
	//		printf("a[%d] = %d\n", i, a[i]);
		}
	//for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	//printf("%d: %d\n", n, cnt);
	//if(cnt != 9 && cnt > max) max = cnt;
	printf("%d\n", cnt);
	return 0;
}
