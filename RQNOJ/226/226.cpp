#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
#define MAXN 210

int n;
char s[MAXN][1000000];
int g[MAXN]={0};
int ans=0;
bool h[MAXN]={0};
int jmp[MAXN]={0};

int main()
{
    //freopen("asm.in","r",stdin);
    //freopen("asm.out","w",stdout);
    
    scanf("%d\n",&n);
    string ch;
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
        if(!strcmp(s[i],"jmp"))
        {
            h[i]=true;
            scanf("%d",&x);
            jmp[i]=x;
        }
        getline(cin,ch);//跳行
    }
    int i=1;
    char temp[100];
    memset(temp,0,sizeof(temp));
    while(i<=n)
    {
        g[i]++;ans++;
        if(g[i]==2) {printf("0");exit(0);}
        if(h[i]) {i=jmp[i];continue;}
        i++;
    }
    printf("%d",ans);
    
    return 0;
}

