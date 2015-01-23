/*
ID: jiangzh15
TASK: clocks
LANG: C++
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
using namespace std;

const int kkk[]={1,1,4,16,64,256,1024,4096,16384,65536};//hash表中要用
const int ddd[10][10]={    //A B C D E F G H I
                          {0,0,0,0,0,0,0,0,0,0},
                          {0,1,1,0,1,1,0,0,0,0},//1        ABDE
                          {0,1,1,1,0,0,0,0,0,0},//2        ABC
                          {0,0,1,1,0,1,1,0,0,0},//3        BCEF
                          {0,1,0,0,1,0,0,1,0,0},//4        ADG
                          {0,0,1,0,1,1,1,0,1,0},//5        BDEFH
                          {0,0,0,1,0,0,1,0,0,1},//6        CFI
                          {0,0,0,0,1,1,0,1,1,0},//7        DEGH
                          {0,0,0,0,0,0,0,1,1,1},//8        GHI
                          {0,0,0,0,0,1,1,0,1,1},//9        EFHI
                      };
struct node{int a[10],step,c[50],way[10];};
queue<node> q;
node first;
bool h[262143+100];

int gethash(node x)
{
    int sum=0;
    for(int i=1;i<=9;i++)
        sum+=x.a[i]*kkk[i];
    return sum;
}

void check(node x)
{
    for(int i=1;i<=9;i++)
        if(x.a[i]!=0)return;
    for(int i=1;i<=x.step-1;i++) printf("%d ",x.c[i]);
    printf("%d\n",x.c[x.step]);
    exit(0);
}

int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    int i,j;
    for(i=1;i<=9;i++)
        {scanf("%d",&first.a[i]);first.a[i]=(first.a[i]%12)/3;}
    first.step=0;
    check(first);
    q.push(first);
    while(!q.empty())
    {
        node newnd,nd=q.front();q.pop();
        //printf("%d\n",nd.step);
        for(i=1;i<=9;i++)
        {
            if(nd.way[i]>=3)continue;
            newnd=nd;
            newnd.step++;
            newnd.way[i]++;
            for(j=1;j<=9;j++)
            {
                newnd.a[j]+=ddd[i][j];
                if(newnd.a[j]>=4)newnd.a[j]-=4;
            }
            newnd.c[newnd.step]=i;
            if(!h[gethash(newnd)])
            {
                /*printf("step=%d    ",newnd.step);
                for(int kk=1;kk<=newnd.step;kk++)
                    printf("%d ",newnd.c[kk]);
                printf("\n");*/
                check(newnd);
                h[gethash(newnd)]=true;
                q.push(newnd);
            }
        }
    }
    return 0;
}
