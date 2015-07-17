#include <cstdio>

int n, v, cnt = 0, hash[1000];

int main()
{
	scanf("%d%d", &n, &v);
	for(int i = 1; i <= n; i++)
	{
		int k; scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			int x; scanf("%d", &x);
			if(x < v)
			{
				if(!hash[i]) cnt++;
				hash[i] = 1;
			}
		}
	}
	printf("%d\n", cnt);
	bool backspace = 0;
	for(int i = 1; i <= n; i++) if(hash[i])
	{
		if(backspace) putchar(' ');
		printf("%d", i);
		backspace = 1;
	}
	return 0;
}
