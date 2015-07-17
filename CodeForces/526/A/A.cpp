#include <cstdio>

int n, a[10];
char s[200];

bool check()
{
	for(int st = 1; st <= n; st++)
		for(int len = 1; len <= n; len++)
		{
			bool flag = 1;
			a[1] = st;
			for(int i = 2; i <= 5; i++)
			{
				a[i] = a[i-1] + len;
				if(a[i] > n)
				{
					flag = 0;
					break;
				}
			}
			if(!flag) break;
			flag = 1;
			for(int i = 1; i <= 5; i++)
				if(s[a[i]] != '*') flag = 0;
			if(flag) return 1;
		}
	return 0;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	if(check()) puts("yes"); else puts("no");
	return 0;
}
