#include <cstdio>
#include <cstring>

int h, w, n;
char s[200];

int main()
{
	scanf("%d%d%d", &h, &w, &n);
	int lines = 1;
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		now += len;
		if(now == w)
		{
			now = 0;
			lines++;
			continue;
		}
		if(now > w)
		{
			now = len;
			lines++;
		}
		if(now < w)
		{
			now++;
		}
	}
	if(!now) lines--;
	printf("%d\n", (lines + h - 1) / h);
	return 0;
}
