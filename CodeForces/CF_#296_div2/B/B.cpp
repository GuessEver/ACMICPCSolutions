#include <cstdio>
#include <cstring>

int n;
int d1['z'+10]['z'+10], d2['z'+10]['z'+10];
char s[200010], t[200010];
int wrong['z'+10];

int main()
{
	scanf("%d", &n);
	scanf("%s%s", s, t);
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	int res = 0;
	for(int i = 0; i < n; i++)
		if(s[i] != t[i])
		{
			d1[s[i]][t[i]] = i + 1;
			d2[t[i]][s[i]] = i + 1;
			wrong[t[i]] = i + 1;
			res++;
		}
	for(char i = 'a'; i <= 'z'; i++)
		for(char j = 'a'; j <= 'z'; j++)
			if(d1[i][j] != -1 && d2[i][j] != -1)
			{
				printf("%d\n%d %d\n", res - 2, d1[i][j], d2[i][j]);
				return 0;
			}
	for(char i = 'a'; i <= 'z'; i++)
		for(char j = 'a'; j <= 'z'; j++)
			if(wrong[j] && d2[i][j] != -1)
			{
				printf("%d\n%d %d\n", res - 1, wrong[j], d2[i][j]);
				return 0;
			}
	printf("%d\n%d %d\n", res, -1, -1);
	return 0;
}
