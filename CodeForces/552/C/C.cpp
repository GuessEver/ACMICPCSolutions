#include <cstdio>

int m, w;

bool solve()
{
	int delta = 0;
	while(m)
	{
		int a = m % w;
		m /= w;
		//printf("%d,", a);
		a += delta;
		delta = a / w; a %= w;
		if(a != 1 && a != 0 && a != w - 1) return 0;
		if(a == w - 1) { delta++; a = 0; }
	}
	return 1;
}

int main()
{
	scanf("%d%d", &w, &m);
	if(solve()) puts("YES"); else puts("NO");
	return 0;
}
