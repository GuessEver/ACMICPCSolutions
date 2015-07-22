#include <cstdio>
#include <string>
using std::string;
string s;

int main()
{
	for(int i = 1, j = 0; i <= 131072; i++, j = (j + 1) % 26) s += (char)(j + 'a');
	//for(int i = 1, j = 0; i <= 10; i++, j = (j + 1) % 26) s += (char)(j + 'a');
	puts(s.c_str());
	for(int i = s.length() - 1; i >= 0; i--) putchar(s[i]);
	puts("");
	return 0;
}
