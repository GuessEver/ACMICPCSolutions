#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	if(n == 1) printf("1\n1\n");
	else if(n == 2) printf("1\n1\n");
	else if(n == 3) printf("2\n1 3\n");
	else if(n == 4) printf("4\n3 1 4 2\n");
	else{
		printf("%d\n", n);
		bool flag = 0;
		for(int i = 1; i <= n; i += 2)
		{
			if(flag) putchar(' ');
			printf("%d", i);
			flag = 1;
		}
		for(int i = 2; i <= n; i += 2)
		{
			if(flag) putchar(' ');
			printf("%d", i);
			flag = 1;
		}
	}
	return 0;
}
