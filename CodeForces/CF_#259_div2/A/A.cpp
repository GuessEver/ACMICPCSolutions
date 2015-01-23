#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	int l = n/2+1, r= n/2+1;
	for(int i = 1; i <= n/2; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j >= l && j <= r) printf("D");
			else printf("*");
		}
		printf("\n");
		l--; r++;
	}
	for(int j = 1; j <= n; j++) printf("D"); puts("");
	l = 2; r = n-1;
	for(int i = 1; i <= n/2; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j >= l && j <= r) printf("D");
			else printf("*");
		}
		printf("\n");
		l++; r--;
	}
	return 0;
}
