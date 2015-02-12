#include <cstdio>
#include <cstring>
#include <set>
using std::set;

set<unsigned long long> l;
char s[50000 + 10], t[50000 + 10];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		l.clear();
		scanf("%s%s", s, t);
		int len = strlen(s);
		unsigned long long k = 1, res = 0;
		for(int i = len - 1; i >= 0; i--)
		{
			res += k * (s[i] - 'a' + 1);
			k *= 31;
			l.insert(res);
		}
		res = 0;
		int cnt = 0;
		for(int i = 0; t[i]; i++)
		{
			res = res * 31 + (t[i] - 'a' + 1);
			if(l.find(res) != l.end()) cnt++;
		}
		printf("%d\n", ++cnt);
	}
	return 0;
}
