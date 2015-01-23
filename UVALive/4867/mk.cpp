#include <cstdio>

int main()
{
	printf("1000 1000\n");
	for(int i = 1;i <= 1000; i++)
	{
		for(int j = 1; j <= 1000; j++)
			printf("1 ");
		puts("");
	}
	printf("1000 1000\n");
	for(int i = 1;i <= 1000; i++)
	{
		for(int j = 1; j <= 1000; j++)
			printf("0 ");
		puts("");
	}
	printf("0 0\n");
	return 0;
}
