#include <cstdio>

char home[2000], away[2000];
int m;
int foul[10][200];
bool done[10][200];

int main()
{
	scanf("%s", home);
	scanf("%s", away);
	scanf("%d", &m);
	while(m--)
	{
		int t, num, team, s;
		char op[10], f[10];
		scanf("%d%s", &t, op);
		scanf("%d%s", &num, f);
		if(op[0] == 'h') team = 1;
		else team = 2;
		if(f[0] == 'y') s = 1;
		else s = 2;
		foul[team][num] += s;
		if(!done[team][num] && foul[team][num] >= 2)
		{
			done[team][num] = 1;
			if(team == 1) printf("%s", home);
			else printf("%s", away);
			printf(" %d %d\n", num, t);
		}
	}
	return 0;
}
