#include <cstdio>

int ans[1000];

bool ok(int x)
{
	if(x % 7 == 0) return 1;
	if(x % 10 == 7) return 1;
	if((x / 10) % 10 == 7) return 1;
	if(x / 100 == 7) return 1;
	return 0;
}

int main()
{
	for(int i = 7; i <= 701; i++)
	{
		int j;
		for(j = i; j<= 799; j++)
		{
			if(ok(j))
			{
				if(!ans[j-i+1]) ans[j-i+1] = i;
			   	continue;
			}
			else break;
		}
	}
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
