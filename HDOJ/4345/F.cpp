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
ll f[10000],v[10000],n;
int main(){
	
	clr(v,0);
	rep(i,2,1000){
		rep(j,2,ll(sqrt(i*1.0))){
			if ((i%j)==0) v[i]=1;	
		}
	}
	//rep(i,2,20) cout<<i<<" "<<v[i]<<endl;
	clr(f,0);f[0]=1;
	for (ll i=1000;i>=2;i--) if (v[i]==0){
		//cout<<i<<endl;cout<<"!"<<endl;
		for (ll j=1000;j>=i;j--){
			ll k=1;
			while (k*i<=j){
				k*=i;f[j]+=f[j-k];
			}
		}
	}
	
	rep(i,1,1000) f[i]+=f[i-1];
	while (scanf("%d",&n)==1){
		cout<<f[n]<<endl;
	}
	return 0;
}

