#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int n;
string s;

int main()
{
  //freopen("rqn257.in","r",stdin);
  //freopen("rqn257.out","w",stdout);
  getline(cin,s);
  int len=s.length();
  cin>>n;
  //cout<<s<<endl;
//  cout<<len;
  int i,j;
  for(i=1;i<=n;i++)
  {
    j=0;
    while(j<len && s[j]<=s[j+1]) j++;
    s.erase(j,1);
    while(s[0]=='0')s.erase(0,1);
  }
  if(s=="")cout<<'0';
  else cout<<s;
  return 0;
}

