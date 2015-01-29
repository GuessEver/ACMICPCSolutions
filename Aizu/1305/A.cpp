#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
using std::string;
using std::set;
using std::map;

int n;
char tmp[2000];
char Team[200][20];
char empl[200][20][20];
int len[200][20];
int cnt[200];
set<string> hash, ht;
map<string, int> num;

int dfs(int i)
{
	if(ht.find(string(Team[i])) != ht.end())  return 0;
	ht.insert(string(Team[i]));
	int res = 0;
	for(int j = 1; j <= cnt[i]; j++)
	{
		string now(empl[i][j]);
		if(num[now]) res += dfs(num[now]); // Team Name
		else{
			if(hash.find(now) != hash.end()) continue; // Done already
			hash.insert(now);
			res++;
		}
	}
	return res;
}

int main()
{
	freopen("A.in", "r", stdin);
	while(scanf("%d", &n) == 1 && n)
	{
		memset(Team, 0, sizeof(Team));
		memset(empl, 0, sizeof(empl));
		memset(len, 0, sizeof(len));
		memset(cnt, 0, sizeof(cnt));
		num.clear(); hash.clear(); ht.clear();
		for(int i = 1; i <= n; i++)
		{
			fgets(tmp, 1900, stdin);
			char ch = getchar();
			do{
				Team[i][len[i][0]++] = ch;
			}while((ch = getchar()) != ':');
			//printf("Team [%s] :\n", Team[i]);
			num[string(Team[i])] = i;
			while((ch = getchar()) != '.')
			{
				cnt[i]++;
				do{
					empl[i][cnt[i]][len[i][cnt[i]]++] = ch;
					ch = getchar();
				}while(ch != ',' && ch != '.');
				//puts(empl[i][cnt[i]]);
				if(ch == '.') break;
			}
		}
		int res = dfs(1);
		printf("%d\n", res);
	}
	return 0;
}
