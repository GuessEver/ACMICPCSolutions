#include <cstdio>
#include <cstring>

int n;
char a[10][500];
char tmp[500];

void getans(int x, int pos)
{
	if(x == 1) a[1][pos] = '*';
	else if(x == 2) a[1][pos] = a[2][pos] = '*';
	else if(x == 3) a[1][pos] = a[1][pos+1] = '*';
	else if(x == 4) a[1][pos] = a[1][pos+1] = a[2][pos+1] = '*';
	else if(x == 5) a[1][pos] = a[2][pos+1] = '*';
	else if(x == 6) a[1][pos] = a[2][pos] = a[1][pos+1] = '*';
	else if(x == 7) a[1][pos] = a[2][pos] = a[1][pos+1] = a[2][pos+1] = '*';
	else if(x == 8) a[1][pos] = a[2][pos] = a[2][pos+1] = '*';
	else if(x == 9) a[2][pos] = a[1][pos+1] = '*';
	else if(x == 0) a[2][pos] = a[1][pos+1] = a[2][pos+1] = '*';
}

int getnumber(int pos)
{
	if(a[1][pos] == '*' && a[1][pos+1] == '.' && a[2][pos] == '.' && a[2][pos+1] == '.') return 1;
	if(a[1][pos] == '*' && a[1][pos+1] == '.' && a[2][pos] == '*' && a[2][pos+1] == '.') return 2;
	if(a[1][pos] == '*' && a[1][pos+1] == '*' && a[2][pos] == '.' && a[2][pos+1] == '.') return 3;
	if(a[1][pos] == '*' && a[1][pos+1] == '*' && a[2][pos] == '.' && a[2][pos+1] == '*') return 4;
	if(a[1][pos] == '*' && a[1][pos+1] == '.' && a[2][pos] == '.' && a[2][pos+1] == '*') return 5;
	if(a[1][pos] == '*' && a[1][pos+1] == '*' && a[2][pos] == '*' && a[2][pos+1] == '.') return 6;
	if(a[1][pos] == '*' && a[1][pos+1] == '*' && a[2][pos] == '*' && a[2][pos+1] == '*') return 7;
	if(a[1][pos] == '*' && a[1][pos+1] == '.' && a[2][pos] == '*' && a[2][pos+1] == '*') return 8;
	if(a[1][pos] == '.' && a[1][pos+1] == '*' && a[2][pos] == '*' && a[2][pos+1] == '.') return 9;
	if(a[1][pos] == '.' && a[1][pos+1] == '*' && a[2][pos] == '*' && a[2][pos+1] == '*') return 0;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		char op[10]; scanf("%s", op);
		if(op[0] == 'S')
		{
			scanf("%s", tmp);
			memset(a, '.', sizeof(a));
			for(int i = 0; i < n; i++) getans(tmp[i] - '0', i*2);
			for(int i = 1; i <= 3; i++)
			{
				for(int j = 0; j < 2*n; j++)
				{
					printf("%c", a[i][j]);
					if((j&1) && j != 2*n-1) putchar(' ');
				}
				puts("");
			}
		}
		else if(op[0] == 'B')
		{
			for(int i = 1; i <= 3; i++)
				for(int j = 0; j < 2 * n; j++)
				{
					scanf(" %c", &a[i][j]);
				}
			for(int j = 0; j < n; j++) printf("%d", getnumber(j*2));
			puts("");
		}
	}
	return 0;
}
