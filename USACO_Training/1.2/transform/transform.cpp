/*
ID: jiangzh15
TASK: transform
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[20][20],b[20][20],c[20][20];
int n;

bool check(char b[][20],char c[][20])
{
    bool flag=true;
    for(int i=0;i<n;i++)
        if(memcmp(b[i],c[i],n))
        {
            flag=false;
            break;
        }
    return flag;
}

void work(int k)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            switch(k)
            {
                case 1:c[j][n-i-1]=a[i][j];break;
                case 2:c[n-i-1][n-j-1]=a[i][j];break;
                case 3:c[n-j-1][i]=a[i][j];break;
                case 4:c[i][n-j-1]=a[i][j];break;
            }
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d\n",&n);
    int i,j;
    for(i=0;i<n;i++) scanf("%s\n",a[i]);
    for(i=0;i<n;i++) scanf("%s\n",b[i]);
    bool same=check(a,b);
    //printf("\na:\n");for(i=0;i<n;i++)puts(a[i]);
    //printf("\nb:\n");for(i=0;i<n;i++)puts(b[i]);
    for(i=1;i<=4;i++)
    {
        work(i);
        //printf("\ni=%d\n",i);for(j=0;j<n;j++)puts(c[j]);
        if(check(b,c)){printf("%d\n",i);exit(0);}
    }
    //for(i=0;i<n;i++)puts(b[i]);
    work(4);//执行方案5  先翻转
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=c[i][j];
   // printf("\n");for(i=0;i<n;i++)puts(a[i]);
    for(i=1;i<=3;i++)
    {
        work(i);
       // printf("\ni=%d\n",i);for(j=0;j<n;j++)puts(c[j]);
        if(check(b,c)) {printf("5\n");exit(0);}
    }
    if(same){printf("6\n");exit(0);}
    else {printf("7\n");exit(0);}
    return 0;
}
