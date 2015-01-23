#include <cstdio>
#include <string>
#include <iostream>
using std::cin;
using std::string;

string s,t;

int main()
{
	freopen("10340.in", "r", stdin);
	//freopen("10340.out", "w", stdout);
	while(cin >> s >> t)
	{
		int lens = s.length(), lent = t.length();
		int i = 0, j = 0;
		bool flag = 0;
		while(i < lens && j < lent)
		{
			if(s[i] == t[j]) i++;
			j++;
			if(i == lens) flag = 1;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
