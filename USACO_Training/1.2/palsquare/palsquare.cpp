/*
ID: jiangzh15
TASK: palsquare
LANG: C++
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int n;
char num[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

string zhuan(int x,int k)
{
    string s="";
    while(x)
    {
        s+=num[x%k];
        x/=k;
    }
    string ss="";;
    for(int i=s.length()-1;i>=0;i--)
        ss+=s[i];
    return ss;
}

bool hui(string b)
{
    string s;
    for(int i=b.length()-1;i>=0;i--)
        s+=b[i];
    return (s==b);
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d",&n);
    string a,b;
    for(int i=1;i<=300;i++)
    {
        a=zhuan(i,n);
        b=zhuan(i*i,n);
        if(hui(b)) cout<<a<<" "<<b<<endl;
    }
    return 0;
}
