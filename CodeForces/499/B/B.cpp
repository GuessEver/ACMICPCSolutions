#include <cstdio>
#include <map>
#include <string>
using std::map;
using std::string;

map<string, string> hash;
int n, m;
char tmp[100];
string A, B;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%s", tmp); A = string(tmp);
		scanf("%s", tmp); B = string(tmp);
		hash[A] = B;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", tmp); A = string(tmp);
		B = hash[A];
		if(B.length() < A.length()) printf("%s", B.c_str());
		else printf("%s", A.c_str());
		if(i != n) putchar(' '); else puts("");
	}
	return 0;
}
