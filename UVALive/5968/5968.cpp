#include <cstdio>
#include <cstring>

char s[50000];

int main()
{
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		printf("Case %d: ", ++cas);
		scanf("%s", s);
		int len = strlen(s);
		int A = 0, B = 0;
		bool flag = 1;
		for(int i = 0; i < len-1; i++)
		{
			if(s[i] == 'S')
			{
				if(s[i+1] == 'S') A++;
				else B++;
			}
		}
		printf("%d / %d\n", A, B);
	}
	return 0;
}
