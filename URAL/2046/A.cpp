#include <cstdio>
#include <cstring>

char s[10][10][100];
char str[100], day[100];
int n;
char tmp[100];

int main()
{
	//freopen("A.in", "r", stdin);
	scanf("%d", &n);
	fgets(str, 90, stdin);
	for(int i = 1; i <= n; i++)
	{
		fgets(str, 90, stdin);
		int x, y;
		scanf("%s", day); scanf("%d", &y);
		if(!strcmp(day, "Tuesday")) x = 1;
		else if(!strcmp(day, "Thursday")) x = 2;
		else if(!strcmp(day, "Saturday")) x = 3;
		strcpy(s[x][y], str);
		fgets(str, 90, stdin);
	}
	puts("+----------+----------+----------+");
	for(int j = 1; j <= 4; j++)
	{
		int pos[5] = {0};
		bool has = 0;
		while(1)
		{
			bool flag = 0;
			for(int i = 1; i <= 3; i++)
				if(sscanf(s[i][j] + pos[i], "%s", tmp) == 1) flag = 1;
			if(!flag) break;
			has = 1;
			for(int i = 1; i <= 3; i++)
			{
				printf("|");
				int hang = 0;
				while(1)
				{
					memset(tmp, 0, sizeof(tmp));
					sscanf(s[i][j] + pos[i], "%s", tmp);
					int len = strlen(tmp); hang += len + 1;
					if(hang > 10 + 1) { hang -= len + 1; break; }
					if(hang > len + 1) putchar(' ');
					printf("%s", tmp); pos[i] += len + 1;
				};
				hang--;
				for(int t = 1; t <= 10 - hang; t++) putchar(' ');
			}
			puts("|");
		}
		if(!has) puts("|          |          |          |");
		puts("+----------+----------+----------+");
	}
	return 0;
}
