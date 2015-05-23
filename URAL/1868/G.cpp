#include <cstdio>
#include <cstring>

char rank[20][50];
int n;
int correct[200];
char team[50], medal[50];

int calc()
{
	int cnt = 0;
	int m; scanf("%d", &m);
	while(m--)
	{
		scanf("%s%*s%s", team, medal);
		int R = 0;
		for(int i = 1; i <= 12; i++)
			if(!strcmp(team, rank[i]))
			{
				R = i;
				break;
			}
		if(medal[0] == 'g' && R >= 1 && R <= 4) cnt++;
		else if(medal[0] == 's' && R >= 5 && R <= 8) cnt++;
		else if(medal[0] == 'b' && R >= 9 && R <= 12) cnt++;
	}
	return cnt;
}

int main()
{
	for(int i = 1; i <= 12; i++) scanf("%s", rank[i]);
	scanf("%d", &n);
	int maxGuess = 0;
	for(int i = 1; i <= n; i++)
	{
		correct[i] = calc();
		if(correct[i] > maxGuess) maxGuess = correct[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(correct[i] == maxGuess) cnt++;
	printf("%d\n", cnt * 5);
	return 0;
}
