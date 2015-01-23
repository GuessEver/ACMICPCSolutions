#include<cstdio>
#include<string>

char a[200],b[200];
bool ha[30],hb[30];
char ans[30];

int main()
{
    //freopen("spy.in","r",stdin);
    //freopen("spy.out","w",stdout);
    gets(a);
    gets(b);
    for(int i=0;i<strlen(a);i++)
    {
        if(ha[a[i]-'A'] && ans[a[i]-'A']!=b[i]){printf("Failed");exit(0);}
        if(!ha[a[i]-'A'] && hb[b[i]-'A']){printf("Failed");exit(0);}
        ha[a[i]-'A']=true;
        hb[b[i]-'A']=true;
        ans[a[i]-'A']=b[i];
    }
    for(char i='A';i<='Z';i++)
        if(!ha[i-'A']){printf("Failed");exit(0);}
    char ch[200];
    gets(ch);
    for(int i=0;i<strlen(ch);i++)
        printf("%c",ans[ch[i]-'A']);
    return 0;
}

