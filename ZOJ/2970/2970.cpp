#include <cstdio>

char s[100];
int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		scanf("%d", &n);
		int x; scanf("%d", &x);
		int res = x;
		for(int i = 2; i <= n; i++)
		{
			scanf("%d", &x);
			if(s[0] == 'F')
			{
				if(x < res) res = x;
			}
			else {
				if(x > res) res = x;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
