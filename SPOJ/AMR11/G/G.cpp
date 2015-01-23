#include <cstdio>
#include <cstring>

char s[100];

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%s", &s);
		int len = strlen(s);
		bool flag = 0;
		for(int i = 0; i < len; i++)
			if(s[i] == 'D') flag = 1;
		if(flag) printf("You shall not pass!\n");
		else printf("Possible\n");
	}
	return 0;
}
