#include <cstdio>
#include <set>
using std::set;

const int P = 535741;
const int mod = 1000000000 + 7;

inline int getHash(char *s)
{
	int res = 0;
	for(int i = 0; s[i]; i++)
		res = (1ll * res * P + s[i] - '0') % mod;
	return res;
}

char s[110];
set<int> l;

int main()
{
	while(scanf("%s", s) == 1)
	{
		int x = getHash(s);
		if(l.find(x) == l.end()) l.insert(x);
	}
	printf("%d\n", (int)l.size());
	return 0;
}
