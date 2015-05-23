#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
using std::string;
using std::vector;
using std::map;
using std::queue;

int n, L;
char tmpChar[200];
string usr[2000];
map<string, int> hash;
struct Link{
	int y;
	Link *next;
}*head[2000];

void inLink(string A, string B)
{
	if(hash.find(A) == hash.end()) hash[A] = ++L;
	if(hash.find(B) == hash.end()) hash[B] = ++L;
	usr[hash[A]] = A; usr[hash[B]] = B;
	Link *p = new Link;
	p -> y = hash[B];
	p -> next = head[hash[A]];
	head[hash[A]] = p;
}

int dist[2000], dis2[2000];
queue<int> Q;
bool inQ[2000];

void spfa()
{
	memset(dist, 0x3f, sizeof(dist));
	memset(dis2, 0x3f, sizeof(dist));
	fgets(tmpChar, 150, stdin);
	fgets(tmpChar, 150, stdin);
	dist[1] = strlen(tmpChar) - 1; dis2[1] = 0;
	inQ[1] = 1; Q.push(1);
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); inQ[x] = 0;
		for(Link *p = head[x]; p; p = p -> next)
		{
			int tmp = 6 + usr[x].length();
			if(dist[p -> y] > dist[x] + tmp)
			{
				dist[p -> y] = dist[x] + tmp;
				if(!inQ[p -> y])
				{
					inQ[p -> y] = 1;
					Q.push(p -> y);
				}
				if(dis2[p -> y] > dist[p -> y] - usr[x].length())
					dis2[p -> y] = dist[p -> y] - usr[x].length() - 6;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", tmpChar);
		string A(tmpChar);
		if(hash.find(A) == hash.end()) hash[A] = ++L;
		usr[hash[A]] = A;
		int k; scanf("%d", &k);
		while(k--)
		{
			scanf("%s", tmpChar);
			inLink(A, string(tmpChar));
		}
	}
	//printf("%d\n", L);
	//for(int i = 1; i <= L; i++) printf("%s\n", usr[i].c_str());
	//puts("====");
	spfa();
	//for(int i = 1; i <= L; i++) printf("%d ", dist[i]); puts("");
	//for(int i = 1; i <= L; i++) printf("%d ", dis2[i]); puts("");
	int res = 0;
	for(int i = 1; i <= L; i++) if(dis2[i] <= 140) res++;
	printf("%d\n", res);
	for(int i = 1; i <= L; i++) if(dis2[i] <= 140) printf("%s\n", usr[i].c_str());
	return 0;
}
