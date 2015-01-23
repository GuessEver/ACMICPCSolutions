#include <cstdio>
#include <cstring>

long long n;
char s[100];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &n);
		sprintf(s, "%lld", n);
		int len = strlen(s);
		int res = 0;
		for(int i = 0; i < len; i++)
		{
			int div = s[i] - '0';
			if(div && n % div == 0) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
