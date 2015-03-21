#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using std::string;

const int N = 1000 + 10;

char s[N], t[N];
int n;
int f[N][N];
string str[N][N];

int main()
{
	while(scanf("%s", s + 1) == 1)
	{
		n = strlen(s+1);
		for(int i = n; i >= 1; i--) t[n-i+1] = s[i];
		t[n+1] = 0;
		//puts(s+1); puts(t+1);
		memset(f, 0, sizeof(f));
		//for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) str[i][j].assign(1000, 'z');
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(f[i-1][j] > f[i][j] || (f[i-1][j] == f[i][j] && str[i-1][j] < str[i][j]))
				{
					f[i][j] = f[i-1][j];
					str[i][j] = str[i-1][j];
				}
				if(f[i][j-1] > f[i][j] || (f[i][j-1] == f[i][j] && str[i][j-1] < str[i][j]))
				{
					f[i][j] = f[i][j-1];
					str[i][j] = str[i][j-1];
				}
				if(s[i] == t[j] && (f[i][j] < f[i-1][j-1] + 1 || (f[i-1][j-1] + 1 == f[i][j] && str[i-1][j-1] + s[i] < str[i][j])))
				{
					f[i][j] = f[i-1][j-1] + 1;
					str[i][j] = str[i-1][j-1] + s[i];
				}
			}
		/*
		//puts(str[n][n].c_str());
			Attention!!!! For data: cbcabcb
			We may output `bcabc`, but the correct answer is `bcacb`
		*/
		int halflen = f[n][n] / 2;
		for(int i = 0; i < halflen; i++) putchar(str[n][n][i]);
		halflen -= (f[n][n] % 2 == 0);
		for(int i = halflen; i >= 0; i--) putchar(str[n][n][i]);
		puts("");
	}
	return 0;
}
