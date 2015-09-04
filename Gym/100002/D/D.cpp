#include <cstdio>
#include <cstring>
#include <cctype>
const int N = 10000 + 10;
char s1[N*2], s2[N*2], s3[N*2];
int a1[N], a2[N], a3[N];
int n;

inline int NUMBER(char ch)
{
	if(isdigit(ch)) return ch - '0';
	return ch - 'A' + 10;
}

int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	scanf("%s", s1);
	n = strlen(s1) / 2;
	scanf("%s", s2);
	//printf("    ");
	for(int i = 0; i < n; i++)
	{
		int tmp = NUMBER(s1[i*2]) * 16 + NUMBER(s1[i*2+1]);
		//printf("%3d ", tmp);
		a1[i+1] = tmp;
	}
	//puts("");
	for(int i = 0; i < n + 1; i++)
	{
		int tmp = NUMBER(s2[i*2]) * 16 + NUMBER(s2[i*2+1]);
		//printf("%3d ", tmp);
		a2[i] = tmp;
	}
	/*puts(""); scanf("%s", s3);
	for(int i = 0; i < n + 1; i++)
	{
		int tmp = NUMBER(s3[i*2]) * 16 + NUMBER(s3[i*2+1]);
		printf("%3d ", tmp);
	}
	puts("");*/
	a3[0] = 32 ^ a2[0];
	for(int i = 1; i < n + 1; i++)
		a3[i] = a3[i-1] ^ a1[i] ^ a2[i];
	for(int i = 0; i < n + 1; i++)
	{
		//printf("%3d ", a3[i]);
		printf("%02X", a3[i]);
	}
	puts("");
	return 0;
}
