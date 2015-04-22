#include <cstdio>
#include <cstring>

int a[10], b[10], c[10][10][2];
int res[100];
int A, B, n, m;

void pre(int *p, int x, int &num)
{
	char str[10];
	sprintf(str, "%d", x);
	num = strlen(str);
	for(int i = 0; i < num; i++)
		p[i+1] = str[i] - '0';
	//for(int i = 1; i <= num; i++) printf("%d ", p[i]); puts("");
}

int main()
{
	while(scanf("%d%d", &A, &B) == 2 && A && B)
	{
		pre(a, A, m); pre(b, B, n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				c[i][j][0] = a[j] * b[i] / 10;
				c[i][j][1] = a[j] * b[i] % 10;
			}
	/*	for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++) printf("%d:%d ", c[i][j][0], c[i][j][1]);
			puts("");
		}	*/
		memset(res, 0, sizeof(res));
		int cnt = 1;
		for(int i = 1; i <= n; i++, cnt++)
			for(int j = 1, tmp = cnt; j <= m; j++, tmp++)
			{
				res[tmp] += c[i][j][0];
				res[tmp+1] += c[i][j][1];
			}
		//for(int i = 1; i <= cnt+m-1; i++) printf("%d ", res[i]); puts("");
		for(int i = cnt+m-1; i > 1; i--)
		{
			res[i-1] += res[i] / 10;
			res[i] %= 10;
		}
		//for(int i = 1; i <= cnt+m-1; i++) printf("%d ", res[i]); puts("");
		cnt = 0;
		printf("+--"); for(int j = 1; j <= m; j++) printf("----"); puts("-+");
		printf("|  "); for(int j = 1; j <= m; j++) printf(" %d  ", a[j]); puts(" |");
		printf("| +"); for(int j = 1; j <= m; j++) printf("---+"); puts(" |");
		bool ok = 0;
		for(int i = 1; i <= n; i++)
		{
			printf("|%s|", ok ? "/" : " "); 
			for(int j = 1; j <= m; j++) printf("%d /|", c[i][j][0]); puts(" |");
			printf("| |"); for(int j = 1; j <= m; j++) printf(" / |"); printf("%d|\n", b[i]);
			if(!ok && res[cnt+1]) ok = 1;
			if(ok) printf("|%d|", res[++cnt]); else { printf("| |"); cnt++; }
			for(int j = 1; j <= m; j++) printf("/ %d|", c[i][j][1]); puts(" |");
			printf("| +"); for(int j = 1; j <= m; j++) printf("---+"); puts(" |");
		}
		printf("|"); for(int j = 1; j <= m; j++)
		{
			printf("%s %d ", ok ? "/" : " ", res[++cnt]);
			if(!ok && res[cnt+1]) ok = 1;
		}
		puts("   |");
		printf("+--"); for(int j = 1; j <= m; j++) printf("----"); puts("-+");
	}
	return 0;
}
