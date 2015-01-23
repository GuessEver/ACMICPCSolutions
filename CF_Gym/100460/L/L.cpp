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
ll h[100100],k[100100],tmp[100100],a[1001000],n,m,r;
int main(){
	cin>>n>>m;
	ll now=0;
	clr(h,0x3f);r=h[1];
	rep(i,1,n){
		scanf("%I64d%I64d",&k[i],&tmp[i]);
		rep(j,1,k[i]){
			now++;
			scanf("%I64d",&a[now]);
			h[a[now]]=min(h[a[now]],tmp[i]);
		}
	}
	now=0;
	rep(i,1,n){
		ll maxi=-1;
		rep(j,1,k[i]){
			maxi=max(maxi,h[a[++now]]);
		}
		if (maxi!=tmp[i]) {cout<<"Poor memory"<<endl;return 0;}; 
	}	
	cout<<"Good memory"<<endl;
	rep(i,1,m-1){
		if (h[i]==r)  cout<<"1 "; else cout<<h[i]<<" ";
	}
	if (h[m]==r)  cout<<"1"<<endl; else cout<<h[m]<<endl;
	return 0;
}
