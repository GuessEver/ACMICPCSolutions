/*
C++ Code
http://oijzh.cnblogs.com
By jiangzh
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string a[]={"0",
"1","2","6","24","120","720","5040","40320","362880","3628800",
"39916800","479001600","6227020800","87178291200","1307674368000","20922789888000",
"355687428096000","6402373705728000","121645100408832000","2432902008176640000"};
int n,k;

int main()
{
    //freopen("ty1018.in","r",stdin);
    //freopen("ty1018.out","w",stdout);
    scanf("%d%d",&n,&k);
    string s=a[n];
    while(s[s.length()-1]=='0') s.erase(s.length()-1);
    string ans="";
    int t=1;
    for(int i=s.length()-1;i>=0,t<=k;i--,t++)
        if(i>=0) ans=s[i]+ans;
        else break;
    cout<<ans;
    return 0;
}

