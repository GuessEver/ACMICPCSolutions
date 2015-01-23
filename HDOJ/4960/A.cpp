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
ll v[10000],a[10000],f[10000],g[10000],co[5000][2],sumi,sumj,i,j,n,ans,num;
int main(){
	while (scanf("%d",&n) && n!=0){
		rep(i,1,n) scanf("%d",&v[i]);
		rep(i,1,n) scanf("%d",&a[i]);
	//	clr(f,0x3f3f3f3f3f3f3f3f);f[0]=0;
	//	rep(i,2,n)
	//	rep(j,0,n-(i-1)){
	//		f[j+(i-1)]=min(f[j+(i-1)],f[j]+a[i]);
	//	}
	//	rep(i,0,n){
	//		cout<<i<<" "<<f[i]<<endl;
	//	}
		clr(co,0);
		i=1;sumi=v[1];j=n+1;sumj=0;num=0;co[0][2]=n+1;
		while (i<=n) {
			while (v[j-1]+sumj<=sumi && j-1>i) j--,sumj+=v[j];
			//cout<<i<<" "<<sumi<<" "<<j<<" "<<sumj<<endl;
			if (sumi==sumj) co[++num][1]=i,co[num][2]=j;
			i++;sumi+=v[i];
			if (i>=j) break;
		}
	//	rep(i,0,num){cout<<i<<" "<<co[i][1]<<" "<<co[i][2]<<endl;}
		clr(g,0x3f3f3f3f3f3f3f3f);
		g[0]=0;
		rep(i,1,num){
			rep(j,0,i-1){
				//cout<<i<<" "<<j<<endl;
				g[i]=min(g[i],g[j]+a[co[i][1]-co[j][1]]+a[co[j][2]-co[i][2]]);
			}
			//cout<<g[i]<<endl;
		}
		ans=0x3f3f3f3f3f3f3f3f;
		rep(i,0,num){
			ans=min(ans,g[i]+a[co[i][2]-co[i][1]-1]);
			//cout<<i<<" "<<g[i]<<" "<<co[i][2]-co[i][1]-1<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
