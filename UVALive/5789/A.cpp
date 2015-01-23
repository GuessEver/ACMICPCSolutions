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
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (long long i=l;i<=r;i++)
using namespace std;
int n,m,l[100100],r[100100],x,y,ll,rr;
int main(){
	while (cin>>n>>m && n!=0 && m!=0){
		l[1]=0;rep(i,2,n) l[i]=i-1;
		r[n]=0;rep(i,1,n-1) r[i]=i+1;
		rep(i,1,m){
			cin>>ll>>rr;
			x=l[ll];y=r[rr];
			if (x == 0) cout<<"*";else cout<<x;
			cout<<" ";
			if (y == 0) cout<<"*";else cout<<y;
			cout<<endl;
			if (y!=0) l[y]=x;
			if (x!=0) r[x]=y;
		} 
		cout<<"-"<<endl;
	}
	return 0;
}

