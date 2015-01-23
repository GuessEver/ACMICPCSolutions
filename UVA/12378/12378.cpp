#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
using std::max;

int len;
char s[300000+10], t[300000+10];
int p[300000+10];

void solve()
{
	int i, maxid = 0, id = 0;
	for(int i = 0; i < len; i++)
	{
		if(maxid > i) p[i] = min(p[2*id-i], maxid-i);
		else p[i] = 1;
		while(i+p[i] < len && i-p[i] >= 0 && s[i+p[i]] == s[i-p[i]]) p[i]++;
		if(p[i] + i > maxid)
		{
			maxid = p[i] + i;
			id = i;
		}
	}
	int ans = -1;
	//for(int i = 0; i < len; i++)
	//	printf("%d ", p[i]);
	//printf("\n");
	for(int i = 0; i < len; i++) ans = max(ans, p[i]);
	printf("%d\n", ans / 2);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(p, 0, sizeof(p));
		scanf("%s", t); 
		len = strlen(t);
		int cnt = 0;
		s[cnt++] = '#';
		for(int i = 0; i < len; i++)
			if(i == 0 || t[i] != t[i-1])
			{
				s[cnt++] = t[i];
				s[cnt++] = '#';
			}
		len = cnt;  s[len] = 0;
		//puts(s);
		solve();
	}
	return 0;
}
