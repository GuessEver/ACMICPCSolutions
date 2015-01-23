/**************************************************************
    Problem: 1026
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:816 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50;
int a,b;
int L[N],R[N];
int len;
int f[N][2][2][15];
 
void predoing(int a,int *num)
{
    int le=0;
    while(a)
    {
        num[++le]=a%10;
        a/=10;
    }
    len=max(len,le);
}
 
int calc(int pos,int d,int u,int last,bool zero)
{
    if(pos==0) return 1;
    int &res=f[pos][d][u][last];
    if(res!=-1) return res;
    int st=d?0:L[pos];
    int ed=u?9:R[pos];
    res=0;
    for(int i=st;i<=ed;i++)
    {
        if(abs(i-last)>=2||zero)
        {
            res+=calc(pos-1,d||i>L[pos],u||i<R[pos],i,i==0&&zero);
        }
    }
    return res;
}
 
int main()
{
    memset(f,-1,sizeof(f));
    scanf("%d%d",&a,&b);
    predoing(a,L);predoing(b,R);
    printf("%d\n",calc(len,0,0,0,1));
    return 0;
}
