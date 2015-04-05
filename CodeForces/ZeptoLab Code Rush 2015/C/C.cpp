#include <cstdio>
#include <algorithm>
#include <iostream>

int C, hr, hb, wr, wb;

long long calc1(int y)
{
	if(y < 0) return 0;
	int x = (C - y * wb) / wr;
	//printf("x = %d y = %d\n", x, y);
	return 1ll * hr * x + 1ll * hb * y;
}
long long calc2(int x)
{
	if(x < 0) return 0;
	int y = (C - x * wr) / wb;
	//printf("x = %d y = %d\n", x, y);
	return 1ll * hr * x + 1ll * hb * y;
}

int main()
{
	scanf("%d%d%d%d%d", &C, &hr, &hb, &wr, &wb);
	long long res = 0;
	for(int x = C / wr, t = 0; t <= 1000000 && x - t >= 0; x--, t++)
	{
		int y = (C - x * wr) / wb;
		res = std::max(res, 1ll * hr * x + 1ll * hb * y);
	}
	for(int y = C / wb, t = 0; t <= 1000000 && y - t >= 0; y--, t++)
	{
		int x = (C - y * wb) / wr;
		res = std::max(res, 1ll * hr * x + 1ll * hb * y);
	}
	std::cout << res << std::endl;
	/*long long ans = 0;
	for(int x = 0; x <= C / wr; x++)
	{
		int y = (C - x * wr) / wb;
		long long tmp = 1ll * hr * x + 1ll * hb * y;
		if(tmp > ans) ans = tmp;
	}
	if(ans != res) puts("ERROR");
	*/
	return 0;
}
