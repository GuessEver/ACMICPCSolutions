#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (long long i=l;i<=r;i++)
using namespace std;
string st1,st0,tmpst;
char st[10000];
int tmp,n;
int main(){
	st1="desmond";
	cin>>st0;
	int len;len=st0.length();
	if (int(st0.find(st1))!=(-1)) {
		cout<<"I love you, Desmond!"<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	cin>>n;
	rep(i,1,n) { 	
		scanf("%d%s",&tmp,st);
		st0[tmp-1]=st[0];
		int ll=max(1,tmp-6);
		int rr=tmp;
		rep(j,ll,rr){
			tmpst="";
			rep(k,j,j+6) tmpst=tmpst+st0[k-1];
			if (tmpst == st1) {
				cout<<"I love you, Desmond!"<<endl;
				cout<<i<<endl;
				return 0;	
			}
		}
	}
	cout<<"Goodbye, my love!"<<endl;	
	return 0;
}
