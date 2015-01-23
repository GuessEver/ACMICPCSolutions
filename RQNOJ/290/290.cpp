#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char s[800];
bool h[800];

int getmax(int l,int r)
{
    memset(h,0,sizeof(h));
    int i=l,j=r,sum=0;
    char tmp;
    
    while(i<=r)
    {
        if(s[i]=='w')i++;
        else {tmp=s[i];break;}
    }
    i=l;
    while(i<=r)
    {
        if(s[i]=='w' || s[i]==tmp)
        {
            if(!h[i]){h[i]=true;sum++;}
            i++;
        }
        else break;
    }
    
    while(j>=l)
    {
        if(s[j]=='w')j--;
        else {tmp=s[j];break;}
    }
    j=r;
    while(j>=l)
    {
        if(s[j]=='w' || s[j]==tmp)
        {
            if(!h[j]){h[j]=true;sum++;}
            j--;
        }
        else break;
    }
    return sum;
}

int main()
{
    //freopen("beads.in","r",stdin);
    //freopen("beads.out","w",stdout);
    scanf("%d",&n);
    int i;
    gets(s);
    for(i=1;i<=n;i++)
    {
        scanf("%c",&s[i]);
        s[i+n]=s[i];
    }
    int ans=0;
    for(i=1;i<=n;i++)
        ans=max(ans,getmax(i,i+n-1));
    printf("%d\n",ans);
    return 0;
}

