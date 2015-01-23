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
bool cmp(double a,double b){
	return a<b;
}
int x[201000],y[201000],n,ax,ay,bx,by,q,r1,r2;
double d1[201000],d2[2010000];
using namespace std;
int main(){
	int cas=0,tmp,l,r,mid;
	while (cin>>n && n>0){
		printf("Case %d:\n",++cas);
		rep(i,1,n){
			cin>>x[i]>>y[i];
		}
		cin>>ax>>ay>>bx>>by>>q;
		d1[0]=0;d2[0]=0;
		rep(i,1,n){
			d1[i]=(x[i]-ax)*(x[i]-ax)+(y[i]-ay)*(y[i]-ay);
			d2[i]=(x[i]-bx)*(x[i]-bx)+(y[i]-by)*(y[i]-by);
		}
		sort(d1+1,d1+1+n,cmp);
		sort(d2+1,d2+1+n,cmp);
		rep(i,1,q){
			cin>>r1>>r2;
			tmp=0;
			r1*=r1;r2*=r2;
			l=0;r=n; int ans;
			while (l<=r){
				//cout<<l<<" "<<r<<endl;
				mid=(l+r)/2;
				if (d1[mid]<=double(r1)) {
					l=mid+1; ans = mid;
				}else r=mid-1;
			}
			//cout<<"ans="<<ans<<endl;
			tmp+=ans;
			l=0;r=n;
			while (l<=r){
				mid=(l+r)/2;
				if (d2[mid]<=double(r2)) {
					l=mid+1; ans=mid;	
				} else r=mid-1;
			}
			//cout<<"ans="<<ans<<endl;
			tmp+=ans;
			if (tmp<=n) printf("%d\n",n-tmp); else printf("%d\n",0);
		}
	}
	return 0;
}

