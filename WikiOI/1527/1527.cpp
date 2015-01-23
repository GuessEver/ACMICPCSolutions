#include<cstdio>
char s[1000];
int main()
{
    scanf("%s",s);
    int k;scanf("%d",&k);
    printf("%c\n",s[--k]);
    return 0;
}
