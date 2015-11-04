#include <cstdio>
#include <cstring>
int n, m;
char s[20];
char ans[1000][1000];

void color(const char *op, int L)
{
	for(int i = 0; i < n; i++)
	{
		if(op[0] == '1') ans[0][L + i + 1] = '-';
		if(op[1] == '1') ans[i + 1][L] = '|';
		if(op[2] == '1') ans[i + 1][L + n + 1] = '|';
		if(op[3] == '1') ans[n + 1][L + i + 1] = '-';
		if(op[4] == '1') ans[i + 1 + n + 1][L] = '|';
		if(op[5] == '1') ans[i + 1 + n + 1][L + n + 1] = '|';
		if(op[6] == '1') ans[n + 1 + n + 1][L + i + 1] = '-';
	}
}

void solve(int x, int L)
{
	if(x == 0) color("1110111", L);
	else if(x == 1) color("0010010", L);
	else if(x == 2) color("1011101", L);
	else if(x == 3) color("1011011", L);
	else if(x == 4) color("0111010", L);
	else if(x == 5) color("1101011", L);
	else if(x == 6) color("1101111", L);
	else if(x == 7) color("1010010", L);
	else if(x == 8) color("1111111", L);
	else if(x == 9) color("1111011", L);
}

int main()
{
	int isFirst = 1;
	while(scanf("%d%s", &n, s) == 2)
	{
		if(n == 0 && !strcmp(s, "0")) break;
		m = strlen(s);
		int len = (n + 2) * m + m - 1;
		memset(ans, ' ', sizeof(ans));
		int pre = 0;
		for(int i = 0; s[i]; i++)
		{
			int x = s[i] - '0';
			solve(x, (n + 2) * i + i);
		}
		if(!isFirst) puts("");
		isFirst = 0;
		for(int i = 0; i < 2 * n + 3; i++)
		{
			for(int j = 0; j < len; j++) putchar(ans[i][j]);
			puts("");
		}
	}
	return 0;
}
