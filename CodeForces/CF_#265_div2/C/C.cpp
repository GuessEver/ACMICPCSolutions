#include <cstdio>

int n, p;
char tmp[1010];
int a[1010];

bool check(int i, int now)
{
	if(i >= 2 && now == a[i-1]) return 0;
	if(i >= 3 && now == a[i-2]) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &p);
	scanf("%s", tmp);
	for(int i = 0; i < n; i++) a[i+1] = tmp[i] - 'a' + 1;
	bool flag = 0;
	int k = -1;
	for(int i = n; i > 0; i--)
	{
		int now = a[i];
		while(now < p && ++now)
		{
			if(!check(i, now)) continue;
			flag = 1; k = i;
			break;
		}
		if(flag) { a[i] = now; break; } 
	}
	if(!flag) puts("NO");
	else {
		for(int i = k + 1; i <= n; i++)
			for(int j = 1; j <= 26; j++)
				if(check(i, j))
				{
					a[i] = j;
					break;
				}
		for(int i = 1; i <= n; i++) putchar(a[i] + 'a' - 1);
		puts("");
	}
	return 0;
}
