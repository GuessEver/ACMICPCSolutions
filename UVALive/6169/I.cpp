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
#include <iomanip>
using namespace std;

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
long long aa,a,b,c,d,e,sum,now,tmp,ans,rest,g[10],f[10];
double r;
int init(){
	cin>>f[0]>>f[1]>>f[2]>>f[3]>>f[4]>>f[5]>>f[6];
	sum=f[0]+f[1]+f[2]+f[3]+f[4]+f[5]+f[6];
	if (sum == 0 ) return 0;else return 1;
}
int main(){
	g[0]=g[1]=g[2]=20;g[3]=g[4]=25;g[5]=g[6]=30;
	while (init() == 1){
		int ans=0;now=0;
		//cout<<aa<<a<<b<<c<<d<<e<<f<<endl;
		for(int i=0;i<=6;i++){
			if (f[i]<=0) {now=0;rest=0;continue;};
			now=f[i];
			tmp=now/g[i];
			ans+=tmp;
			rest=now-tmp*g[i];
			if (rest>0) {
				f[i+1]-=g[i]-rest;
				ans++;
				rest=0;
				now=0;
			}
			//cout<<i<<" "<<ans<<"   "<<f[0]<<" "<<f[1]<<" "<<f[2]<<" "<<f[3]<<" "<<f[4]<<" "<<f[5]<<" "<<f[6]<<endl;
		}
		cout<<ans<<endl;
	}
		return 0;
}
