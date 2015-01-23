#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[1000],b[1000],c[1000];
bool ha['Z'+100],hb['Z'+100];
char ans['Z'+100];

void wrong()
{printf("Failed");exit(0);}

int main()
{
    gets(a); gets(b);
    for(int i=0;i<strlen(a);i++)
    {
        if(ha[a[i]] && ans[a[i]]!=b[i]) wrong();
        if(!ha[a[i]] && hb[b[i]]) wrong();
        ha[a[i]]=hb[b[i]]=true;
        ans[a[i]]=b[i];
    }
    for(int i='A';i<='Z';i++)
        if(!ha[i]) wrong();
    gets(c);
    for(int i=0;i<strlen(c);i++)
        printf("%c",ans[c[i]]);
    return 0;
}
