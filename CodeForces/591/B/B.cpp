#include <cstdio>
#include <vector>
using std::vector;
int n, m;
char s[200000+10];
vector<int> pos[300];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for(int i = 0; i < n; i++) pos[s[i]].push_back(i);
	for(int i = 1; i <= m; i++)
	{
		char x, y; scanf(" %c %c", &x, &y);
		std::swap(pos[x], pos[y]);
	}
	for(int i = 'a'; i <= 'z'; i++)
		for(vector<int>::iterator it = pos[i].begin(); it != pos[i].end(); it++)
			s[*it] = i;
	puts(s);
	return 0;
}
