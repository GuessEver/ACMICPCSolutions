#include <cstdio>
#include <cstring>

char key[100][100] = {
	"qwertyuiop",
	"asdfghjkl;",
	"zxcvbnm,./"
};

int main()
{
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	char op; scanf(" %c", &op);
	int dir = (op == 'R') ? -1 : 1;
	while(scanf(" %c", &op) == 1)
	{
		int x, y;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 10; j++)
				if(op == key[i][j])
				{
					x = i; y = j;
					break;
				}
		y += dir;
		putchar(key[x][y]); 
	}
	puts("");
	return 0;
}
