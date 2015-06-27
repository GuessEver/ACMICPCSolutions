#include <cstdio>

int n;
char s[200010];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int tmp = 0, res = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1') tmp++;
		else tmp--;
	}
	printf("%d\n", tmp > 0 ? tmp : -tmp);
	return 0;
}
