#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::set;

string s;
int n;
long long res = 0;
set<string> l;

void calc(int k)
{
	string prefix = "", suffix = "";
	for(int i = 0; i < k; i++) prefix += s[i];
	for(int i = k; i < n; i++) suffix += s[i];
	for(char j = 'a'; j <= 'z'; j++)
	{
		string tmp = prefix + j + suffix;
		if(l.find(tmp) == l.end())
		{
			res++;
			l.insert(tmp);
		}
	}
}

int main()
{
	cin >> s; n = s.length();
	for(int i = 0; i <= n; i++) calc(i);
	printf("%I64d\n", res);
	return 0;
}

