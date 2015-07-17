#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using std::map;

const int N = 100000 + 10;

int w[30];
char s[N];
map<long long, long long> f[30];

int main()
{
	for(int i = 0; i < 26; i++) scanf("%d", &w[i]);
	scanf("%s", s);
	long long res = 0, cnt = 0;
	for(int i = 0; s[i]; i++)
	{
		int x = s[i] - 'a';
		res += f[x][cnt];
		cnt += w[x];
		f[x][cnt]++;
	}
	std::cout << res << std::endl;
	return 0;
}
