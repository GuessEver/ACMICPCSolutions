#include <cstdio>
#include <cstdlib>

int main()
{
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if(x1 == x2)
	{
		int a = abs(y1 - y2);
		if(x1 + a <= 1000 && x2 + a <= 1000) 
			printf("%d %d %d %d\n", x1+a, y1, x2+a, y2);
		else if(x1 - a >= -1000 && x2 - a >= -1000)
			printf("%d %d %d %d\n", x1-a, y1, x2-a, y2);
		else puts("-1");
		return 0;
	}
	if(y1 == y2)
	{
		int a = abs(x1 - x2);
		if(y1 + a <= 1000 && y2 + a <= 1000) 
			printf("%d %d %d %d\n", x1, y1+a, x2, y2+a);
		else if(y1 - a >= -1000 && y2 - a >= -1000) 
			printf("%d %d %d %d\n", x1, y1-a, x2, y2-a);
		else puts("-1");
		return 0;
	}
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	if(a != b)
	{
		puts("-1");
		return 0;
	}
	if(x1 < x2)
	{
		if(y1 < y2)
		{
			if(y1 + a <= 1000 && y2 - a >= -1000)
				printf("%d %d %d %d\n", x1, y1+a, x2, y2-a);
			else puts("-1");
		}
		else{
			if(y1 - a >= -1000 && y2 + a <= 1000)
				printf("%d %d %d %d\n", x1, y1-a, x2, y2+a);
			else puts("-1");
		}
	}
	else{
		if(y1 < y2) printf("%d %d %d %d\n", x1, y1+a, x2, y2-a);
		else printf("%d %d %d %d\n", x1, y1-a, x2, y2+a);
	}
	return 0;
}
