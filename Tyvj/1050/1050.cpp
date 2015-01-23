/*
C++ Code
http://blog.csdn.net/jiangzh7
*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

string a,b;
int lcm[2010][2010];

int main()
{
    freopen("ty1050.in","r",stdin);
    freopen("ty1050.out","w",stdout);
    cin>>a>>b;
    a='0'+a;b='0'+b;//改成1基准，保证后面 -1 不越界
    int maxx=0;
    for(int i=1;i<=a.length();i++)
        for(int j=1;j<b.length();j++)
        {
            if(a[i]!=b[j]) lcm[i][j]=max(lcm[i-1][j],lcm[i][j-1]);
            else lcm[i][j]=max(lcm[i][j],lcm[i-1][j-1]+1);
            maxx=max(maxx,lcm[i][j]);
        }
    printf("%d",maxx);
    return 0;
}

