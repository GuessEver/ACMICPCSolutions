#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using std::string;
const int N = 50 + 10;

int n;
string s[N];

bool cmp(string a, string b)
{
	string tmp1 = a + b;
	string tmp2 = b + a;
	return tmp1 > tmp2;
}

int main()
{
	freopen("10905.in", "r", stdin);
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) std::cin >> s[i];
		std::sort(s+1, s+1+n, cmp);
		for(int i = 1; i <= n; i++) std::cout << s[i];
		printf("\n");
	}
	return 0;
}
