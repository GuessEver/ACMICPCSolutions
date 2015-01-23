#include <cstdio>

int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = n; i >= 0; i--)
		{
			int x; scanf("%d", &x);
			if(i) printf("%d", x * i);
			if(i > 1) printf(" ");
		}
		if(!n) printf("0");
		printf("\n");
	}
	return 0;
}
