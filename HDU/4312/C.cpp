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
struct Node{
	long long  x,y,z,w;
}a[100100];
bool cmp1(Node a,Node b){
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmp2(Node a,Node b){
	if (a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
int main(){
	ll ttt;cin>>ttt;
	while (ttt--){
		ll n;cin>>n;
		rep(i,1,n) scanf("%I64d%I64d",&a[i].x,&a[i].y),a[i].z=a[i].w=0;
		rep(i,1,n){
			ll tmpx=a[i].x,tmpy=a[i].y;
			a[i].x=tmpx+tmpy;
			a[i].y=tmpx-tmpy;
		}
		sort(a+1,a+1+n,cmp1);
		rep(i,1,n) a[1].z+=a[i].x-a[1].x;
		rep(i,2,n){
			a[i].z=a[i-1].z+(i-1)*(a[i].x-a[i-1].x)-(n-i+1)*(a[i].x-a[i-1].x);
		}
		//rep(i,1,n) cout<<i<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<a[i].w<<endl;
		sort(a+1,a+1+n,cmp2);
		rep(i,1,n) a[1].w+=a[i].y-a[1].y;
		//cout<<a[1].w<<endl;
		rep(i,2,n){
			a[i].w=a[i-1].w+(i-1)*(a[i].y-a[i-1].y)-(n-i+1)*(a[i].y-a[i-1].y);
		}
			//	rep(i,1,n)
			//cout<<i<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<a[i].w<<endl;
		ll ans=0x3f3f3f3f3f3f3f3fll,tmp=0;
		rep(i,1,n){
			if (ans>a[i].w+a[i].z) ans=a[i].w+a[i].z,tmp=i;
		}
		cout<<(ans>>1)<<endl;
	}
	return 0;
}
