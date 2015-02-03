#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using std::string;
using std::map;

int n, m;
char tmp[100], temp[100];
unsigned long long cap[10010][20];
struct Node{
	unsigned long long a, b;
	int idx;
}s[10010];

unsigned long long hash(char *p)
{// 传说中大白书上的乱搞取模hash
	unsigned long long res = 0;
	for(int i = 0; p[i]; i++)
		res = res * 137 + p[i]; // multiply a prime number
	return res;
}

void Read()
{
	scanf("%d%d", &n, &m);
	fgets(tmp, 90, stdin);
	for(int i = 1; i <= n; i++)
	{
		fgets(tmp, 90, stdin);
		int j = -1, len = 0;
		for(int cnt = 1, len; cnt <= m; cnt++)
		{
			for(j++, len=0; tmp[j]!=',' && tmp[j]!='\n' && tmp[j]; j++)
				temp[len++] = tmp[j];
			temp[len++] = 0;
			cap[i][cnt] = hash(temp);
			//puts(temp);
			//printf("    %llu\n", cap[i][cnt]);
		}
	}
}

bool cmp(Node x, Node y)
{
	if(x.a == y.a) return x.b < y.b;
	return x.a < y.a;
}

bool Solve()
{
	for(int l = 1; l <= m; l++)
	for(int r = l+1; r <= m; r++)
	{
		for(int i = 1; i <= n; i++)
		{
			s[i].idx = i;
			s[i].a = cap[i][l];
			s[i].b = cap[i][r];
		}
		std::sort(s+1, s+1+n, cmp);
		int i = 1, j = 2;
		for(int i = 2; i <= n; i++)
			if(s[i-1].a == s[i].a && s[i-1].b == s[i].b)
			{
				puts("NO");
				int st = std::min(s[i-1].idx, s[i].idx);
				int ed = std::max(s[i-1].idx, s[i].idx);
				printf("%d %d\n%d %d\n", st, ed, l, r);
				return 0;
			}
	}
	return 1;
}

int main()
{
	Read();
	if(Solve()) puts("YES");;
	return 0;
}
