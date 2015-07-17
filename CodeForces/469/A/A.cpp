#include <cstdio>

int n, hash[200];
int cnt = 0;

int main()
{
	scanf("%d", &n);
	for(int t = 1; t <= 2; t++)
	{
		int p; scanf("%d", &p);
		for(int i = 1; i <= p; i++)
		{
			int x; scanf("%d", &x);
			if(!hash[x]) cnt++;
			hash[x] = 1;
		}
	}
	if(cnt == n) puts("I become the guy.");
	else puts("Oh, my keyboard!");
	return 0;
}
