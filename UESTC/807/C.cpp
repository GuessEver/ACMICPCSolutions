#include <cstdio>
#include <string>
#include <algorithm>
using std::string;

const int N = 100000 + 10;

int n;
string s[N];
char tmp[N];

void solve()
{
	std::sort(s+1, s+1+n);
	//for(int i = 1; i <= n; i++) puts(s[i].c_str());
	long long res = 0;//s[1].length() - 1;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j < s[i].length(); j++)
			if(s[i][j] != s[i-1][j])
			{
				res += j + 1;
				break;
			}
	printf("%lld.000000\n", res);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", tmp);
		s[i] = tmp;
	}
	solve();
	return 0;
}
