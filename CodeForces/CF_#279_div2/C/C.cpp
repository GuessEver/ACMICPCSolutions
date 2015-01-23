#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000000+10;

char s[N];
long long a, b;
int len;
int left[N], right[N];

int main()
{
	scanf("%s", s); len = strlen(s);
	scanf("%I64d%I64d", &a, &b);
	int now = 0;
	for(int i = 0; i < len; i++)
	{
		now = now * 10 + s[i] - '0';
		now %= a;
		left[i] = now;
	}
	now = 0; long long k = 1;
	for(int i = len-1; i >= 0; i--)
	{
		now = ((long long)now  + (s[i] - '0') * k) % b;
		k = (k * 10) % b;
		right[i] = now;
	}
	//for(int i = 0; i < len; i++) printf("%d ", left[i]); puts("");
	//for(int i = 0; i < len; i++) printf("%d ", right[i]); puts("");
	for(int i = 0; i < len-1; i++)
		if(left[i] == 0 && s[i+1] != '0' && right[i+1] == 0)
		{
			puts("YES");
			for(int j = 0; j < len; j++)
			{
				putchar(s[j]);
				if(j == i) puts("");
			}
			puts(""); return 0;
		}
	puts("NO");
	return 0;
}
