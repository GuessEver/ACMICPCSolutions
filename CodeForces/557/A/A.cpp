#include <cstdio>

int n, a[3], l[3], r[3];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < 3; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		a[i] = l[i];
		n -= a[i];
	}
	for(int i = 0; i < 3; i++)
		while(n && a[i] < r[i])
		{
			a[i]++;
			n--;
		}
	printf("%d %d %d\n", a[0], a[1], a[2]);
	return 0;
}
