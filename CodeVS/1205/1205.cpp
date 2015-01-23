#include<cstdio>

char s[1000][1000];

int main()
{
	int n=0;
	while(scanf("%s",s[n++])!=EOF);n--;
	for(int i=n-1;i>0;i--) printf("%s ",s[i]);
	printf("%s\n",s[0]);
	return 0;
}
