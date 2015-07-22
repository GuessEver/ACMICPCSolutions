#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using std::string;
using std::map;
using std::set;

const int N = 10000 + 10;

int n;
string name[N][3];
map<string, int> cnt;
char tmp[30];
set<string> ans[3];

bool cmp(string a, string b)
{
	return cnt[a] > cnt[b];
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		ans[0].clear(); ans[1].clear(); ans[2].clear(); cnt.clear();
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 3; j++)
			{
				scanf("%s", tmp);
				name[i][j] = tmp;
				cnt[name[i][j]]++;
			}
		for(int i = 1; i <= n; i++)
		{
			std::sort(name[i], name[i]+3, cmp);
			//for(int j = 0; j < 3; j++) printf("%s%s", name[i][j].c_str(), j == 2 ? "\n" : " ");
			//for(int j = 0; j < 3; j++) printf("%d%s", cnt[name[i][j].c_str()], j == 2 ? "\n" : " ");
			if(cnt[name[i][0]] == cnt[name[i][2]]) // [0] = [1] = [2]
			{
				ans[0].insert(name[i][0]); ans[0].insert(name[i][1]); ans[0].insert(name[i][2]);
				ans[1].insert(name[i][0]); ans[1].insert(name[i][1]); ans[1].insert(name[i][2]);
				ans[2].insert(name[i][0]); ans[2].insert(name[i][1]); ans[2].insert(name[i][2]);
			}
			else {
				if(cnt[name[i][0]] == cnt[name[i][1]]) // [0] = [1] > [2]
				{
					ans[0].insert(name[i][0]); ans[0].insert(name[i][1]);
					ans[1].insert(name[i][0]); ans[1].insert(name[i][1]);
					ans[2].insert(name[i][2]);
				}
				else if(cnt[name[i][1]] == cnt[name[i][2]]) // [0] > [1] = [2]
				{
					ans[0].insert(name[i][0]);
					ans[1].insert(name[i][1]); ans[1].insert(name[i][2]);
					ans[2].insert(name[i][1]); ans[2].insert(name[i][2]);
				}
				else { // [0] > [1] > [2]
					ans[0].insert(name[i][0]);
					ans[1].insert(name[i][1]);
					ans[2].insert(name[i][2]);
				}
			}
		}
		printf("Case %d: %d %d %d\n", ++cas, (int)ans[0].size(), (int)ans[1].size(), (int)ans[2].size());
	}
	return 0;
}
