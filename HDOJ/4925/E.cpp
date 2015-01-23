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
ll ttt,tmp,sum,n,m,ans;
int main(){
	cin>>ttt;
	while (ttt--){
		cin>>n>>m;
		tmp=0;sum=0;
		rep(i,1,n)
		rep(j,1,m){
			if ((i+j)%2 == 1 ) {
				tmp=1;
				if (i>1) tmp*=2;
				if (i<n) tmp*=2;
				if (j>1) tmp*=2;
				if (j<m) tmp*=2;
				sum+=tmp;
				//cout<<i<<" "<<j<<" "<<tmp<<endl;
			} 
		}
		ans=sum;
		sum=0;
		rep(i,1,n)
		rep(j,1,m){
			if ((i+j)%2 == 0 ) {
				tmp=1;
				if (i>1) tmp*=2;
				if (i<n) tmp*=2;
				if (j>1) tmp*=2;
				if (j<m) tmp*=2;
				sum+=tmp;
				//cout<<i<<" "<<j<<" "<<tmp<<endl;
			} 
		}
		if (ans<sum) ans=sum;
		cout<<ans<<endl;
	}
	return 0;
}

