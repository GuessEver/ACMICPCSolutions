#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int A, B; scanf("%d%d", &A, &B);
		int res = 0;
		for(int i = 1; i <= 40000; i++)
		{
			long long tmp = 1ll * i * i;
			if(tmp >= A && tmp <= B) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
