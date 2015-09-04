#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using std::string;

char s[200];
int n;
int maxTimes[200][200];
int f[200][200];
string str[200][200];

inline int getMaxTimes(int st, int len)
{
	int pos1 = st, pos2 = st, res = 0;
	for(int t = 1; ; t++)
	{
		int cnt = 0; pos1 = st;
		for(; cnt < len; pos1++, pos2++, cnt++)
			if(s[pos1] != s[pos2]) break;
		if(cnt == len) res = t;
		else break;
	}
	return res;
}

inline bool check(int l, int r, int k)
{
	int len = (r - l + 1) / k;
	return maxTimes[l][len] >= k;
}

inline string number(int x)
{
	string s = "";
	do{
		char ch = x % 10 + '0';
		s = ch + s;
		x /= 10;
	}while(x);
	return s;
}

int dp(int l, int r)
{
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = r - l + 1;
	str[l][r] = string(s+l, r - l + 1);
	for(int i = 2; i <= r - l + 1; i++)
		if((r - l + 1) % i == 0 && check(l, r, i))
		{
			int tmp = number(i).length() + 2 + dp(l, l + (r - l + 1) / i - 1);
			if(tmp < f[l][r])
			{
				f[l][r] = tmp;
				str[l][r] = number(i) + "(" + str[l][l + (r - l + 1) / i - 1] + ")";
			}
		}
	for(int k = l; k <= r; k++) // [l, k] U [k+1, r]
	{
		int tmp = dp(l, k) + dp(k+1, r);
		if(tmp < f[l][r])
		{
			f[l][r] = tmp;
			str[l][r] = str[l][k] + str[k+1][r];
		}
	}
	return f[l][r];
}

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i = 1; i <= n; i++)
		for(int len = 1; i + len - 1 <= n; len++)
		{
			maxTimes[i][len] = getMaxTimes(i, len);
			//printf("[%d][%d] = %d\n", i, len, maxTimes[i][len]);
		}
	memset(f, -1, sizeof(f));
	dp(1, n);
	//for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) printf("%d %d : %d\n", i, j, f[i][j]);
	//printf("%d\n", f[1][n]);
	std::cout << str[1][n] << std::endl;
	return 0;
}
