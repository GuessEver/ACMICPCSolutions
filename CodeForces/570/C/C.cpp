#include <cstdio>
#include <cstring>
const int N = 300000 + 10;

char s[N], t[N];
int nxt[N];

void getNext(char *t, int len, int *Next)
{
	memset(Next, 0, sizeof(Next)); Next[0] = -1;
	for(int j = 0, k = -1; j < len; )
	{
		if(k == -1 || t[j] == t[k]) Next[++j] = ++k;
		else k = Next[k];
	}
}
int kmp(char *s, int lens, char *t, int lent)
{
	int res = 0;
	getNext(t, lent, nxt);
	for(int i = 0, j = 0; i < lens; )
	{
		if(j == -1 || s[i] == t[j]) { i++; j++; }
		else j = nxt[j];
		if(j == lent) res++; // Bingo! [pos = j - lent]
	}
	return res;
}

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	strcpy(t, "..");
	int res = kmp(s, strlen(s), t, strlen(t));
	//printf("%d\n", res);
	for(int i = 1; i <= m; i++)
	{
		int x; char c;
		scanf("%d %c", &x, &c); x--;
		if(s[x] == '.' && c != '.')
		{
			if((x > 0 && s[x-1] == '.') || (x < n - 1 && s[x+1] == '.')) res--;
			if((x > 0 && s[x-1] == '.') && (x < n - 1 && s[x+1] == '.')) res--;
		}
		else if(s[x] != '.' && c == '.')
		{
			if((x > 0 && s[x-1] == '.') || (x < n - 1 && s[x+1] == '.')) res++;
			if((x > 0 && s[x-1] == '.') && (x < n - 1 && s[x+1] == '.')) res++;
		}
		s[x] = c;
		printf("%d\n", res);
	}
	return 0;
}
