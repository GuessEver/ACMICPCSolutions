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
#define repdown(i,l,r) for (long long i=l;i<=r;i--)
using namespace std;
ll n,f[1100][1100],a[1010][1010];
int main(){
	while (cin>>n && n!=0){
		clr(f,0);
		rep(i,1,n)
		rep(j,1,i) scanf("%lld",&a[i][j]);
		clr(f,0);
		for (ll i=n;i>=1;i--){
			ll tmp=0,tmp1=0;
			for (ll j=0;j<=n-i;j++){
				tmp+=a[i+j][i];
				tmp1=max(tmp1,f[i+1][min(j,n-i-1)]);
				f[i][j]=max(ll(0),tmp+tmp1);
				//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<tmp<<" "<<tmp1<<endl;	
			}
		}
		ll ans=0;
		rep(i,0,n) ans=max(ans,f[1][i]);
		cout<<ans<<endl;
	}
	return 0;
}

