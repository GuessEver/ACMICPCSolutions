#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using std::string;
using std::map;

int n, m;
char tmp[50];
string Team[50];
map<string, int> hash;
int score[50];
int maxR[50], minR[50];
struct Node{int t1, t2;}tie[50];
int L;
struct SC{
	int idx, score;
	bool operator < (const SC &b) const
	{
		return score > b.score;
	}
}D[50];

void Pos(int x)
{
	if(x == 1) printf("1st");
	else if(x == 2) printf("2nd");
	else if(x == 3) printf("3rd");
	else printf("%dth", x);
}

void dfs(int x)
{
	if(x > L)
	{
		for(int i = 1; i <= n; i++)
		{
			D[i].idx = i;
			D[i].score = score[i];
		}
		std::sort(D+1, D+1+n);
		int last = 1;
		for(int r = 1; r <= n; r++)
		{
			int i = D[r].idx, rank;
			if(D[r].score == D[last].score) rank = last;
			else last = rank = r;
			if(minR[i] == -1 || rank < minR[i]) minR[i] = rank;
			if(maxR[i] == -1 || rank > maxR[i]) maxR[i] = rank;
		}
		return;
	}
	score[tie[x].t1] += 3;
	dfs(x+1);
	score[tie[x].t1] -= 3;
	score[tie[x].t2] += 3;
	dfs(x+1);
	score[tie[x].t2] -= 3;
	score[tie[x].t1]++; score[tie[x].t2]++;
	dfs(x+1);
	score[tie[x].t1]--; score[tie[x].t2]--;
}

int main()
{
	bool one = 1;
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		if(!one) puts("");
		one = 0;
		hash.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", tmp);
			Team[i] = string(tmp);
			hash[Team[i]] = i;
		}
		L = 0;
		memset(score, 0, sizeof(score));
		memset(minR, -1, sizeof(minR));
		memset(maxR, -1, sizeof(maxR));
		for(int i = 1; i <= m; i++)
		{
			scanf("%s", tmp); string t1(tmp);
			scanf("%s", tmp); // vs
			scanf("%s", tmp); tmp[strlen(tmp)-1] = 0; // :
			string t2(tmp);
			int x, y; scanf("%d%d", &x, &y);
			if(x == -1 && y == -1)
			{
				tie[++L].t1 = hash[t1];
				tie[L].t2 = hash[t2];
				continue;
			}
			if(x > y) score[hash[t1]] += 3;
			else if(x < y) score[hash[t2]] += 3;
			else{
				score[hash[t1]] += 1;
				score[hash[t2]] += 1;
			}
		}
		dfs(1);
		for(int i = 1; i <= n; i++)
		{
			printf("Team %s can finish as high as ", Team[i].c_str());
			Pos(minR[i]);
			printf(" place and as low as ");
			Pos(maxR[i]);
			puts(" place.");
		}
	}
	return 0;
}
