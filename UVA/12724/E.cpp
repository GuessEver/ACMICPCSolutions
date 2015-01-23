#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
using std::string;
using std::map;
using std::sort;

int n, m;
char word[200][200];
map<string, string> hash;
char s[30000], tmp[100];

int main()
{
	freopen("E.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		hash.clear();
		printf("Case #%d:\n", cas);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", word[i]);
			string a(word[i]);
			sort(word[i], word[i]+a.length());
			string b(word[i]);
			hash[b] = a;
		}
		fgets(s, 3000, stdin);
		for(int i = 1; i <= m; i++)
		{
			fgets(s, 3000, stdin);
			int pos = 0;
			while(sscanf(s+pos, "%s", tmp) == 1)
			{
				if(pos != 0) printf(" ");
				int tmplen = strlen(tmp);
				pos += tmplen + 1;
				sort(tmp, tmp+tmplen);
				string c(tmp);
				printf("%s", hash[c].c_str());
			}
			printf("\n");
		}
	}
	return 0;
}
