#include <cstdio>
#include <cstring>

const char code[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

char str[200000], s[200000];
bool bit[200000];

void Encode()
{
	int len = 0; int pos = 5, tmp = 0;
	int nlen = strlen(s);
	for(int i = 0; i < nlen; i++)
	{
		int x = s[i];
		for(int j = 7; j >= 0; j--)
		{
			bool bit = (x & (1 << j));
			//printf("%d", bit);
			tmp += bit * (1 << pos);
			if(pos-- == 0)
			{
				//printf("  ->  %d\n", tmp);
				str[len++] = code[tmp];
				pos = 5; tmp = 0;
			}
		}
	}
	if(nlen % 3 != 0)
	{
		str[len++] = code[tmp];
		str[len++] = '=';
		if(nlen % 3 == 1) str[len++] = '=';
	}
	str[len] = 0;
	strcpy(s, str);
	//for(int i = 0; i < len; i++) printf("%d", bit[i]); puts("");
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		int k; scanf("%d%s", &k, s);
		while(k--) Encode();
		printf("Case #%d: %s\n", cas, str);
	}
	return 0;
}
