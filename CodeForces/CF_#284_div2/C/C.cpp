#include <cstdio>
#include <cstdlib>

int sx, sy, tx, ty;
int n;

bool check(int a, int b, int c)
{
	long long tmp1 = 1ll * a * sx + 1ll * b * sy + c;
	long long tmp2 = 1ll * a * tx + 1ll * b * ty + c;
	tmp1 /= llabs(tmp1);
	tmp2 /= llabs(tmp2);
	return tmp1 * tmp2 == -1;
}

int main()
{
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &tx, &ty);
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int a, b, c; 
		scanf("%d%d%d", &a, &b, &c);
		if(check(a, b, c)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
