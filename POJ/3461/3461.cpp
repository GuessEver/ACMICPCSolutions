#include <cstdio>
#include <cstring>
// As Template
char s[1000000+10], t[1000000+10];
int lens, lent, next[1000000+10];

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
	getNext(t, lent, next);
	for(int i = 0, j = 0; i < lens; )
	{
		if(j == -1 || s[i] == t[j]) { i++; j++; }
		else j = next[j];
		if(j == lent) res++; // Bingo! [pos = j - lent]
	}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s%s", t, s);
		printf("%d\n", kmp(s, strlen(s), t, strlen(t)));
	}
	return 0;
}
