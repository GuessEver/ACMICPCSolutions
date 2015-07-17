#include <cstdio>

const int N = 100000 + 10;

int n, x, y, a[N];
int who[20000000];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int G = gcd(x, y);
	double tx0 = 1.0 / x, ty0 = 1.0 / y;
	double tx = tx0, ty = ty0;
	int cycle = x / G + y / G;
	for(int i = 1; i < cycle; i++)
	{
		if(tx < ty)
		{
			who[i] = 1;
			tx += tx0;
		}
		else{
			who[i] = 2;
			ty += ty0;
		}
	}
	who[cycle-1] = who[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int tmp = who[a[i]%cycle];
		if(tmp == 1) puts("Vanya");
		else if(tmp == 2) puts("Vova");
		else puts("Both");
	}
	return 0;
}
