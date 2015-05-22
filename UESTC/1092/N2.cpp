#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using std::pair;
using std::vector;

const int P = 102929;
const int mod1 = 1000000000 + 7;
const int mod2 = 1000000000 + 9;

inline int getHash(char *s, int mod)
{
	int res = 0;
	for(int i = 0; s[i]; i++)
		res = (1ll * res * P + s[i] - '0') % mod;
	return res;
}

char s[110];
typedef pair<int, int> pir;
vector<pir> v;

int main()
{
	while(scanf("%s", s) == 1)
		v.push_back(std::make_pair(getHash(s, mod1), getHash(s, mod2)));
	std::sort(v.begin(), v.end());
	int res = std::unique(v.begin(), v.end()) - v.begin();
	printf("%d\n", res);
	return 0;
}
