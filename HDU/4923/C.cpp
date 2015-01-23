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
double tmp,tmp1;
double a[100100],q0[100100],q1[100100];
ll ttt,n;
int main(){
	cin>>ttt;
	while (ttt--){
		cin>>n;
		double ans=0;
		rep(i,1,n) cin>>a[i];
		ll l=1,r=n;
		while (a[l]==0) ++l;
		while (a[r]==1) --r;
		//cout<<l<<" "<<r<<endl;
		if (r<l) {printf("%.6lf\n",ans);continue;};
		ll tail=0,sum0=0,sum1=0;
		a[r+1]=1;
		rep(i,l,r+1){
			if (a[i]==1 && a[i-1]==0 && i!=l){
				++tail;
				q0[tail]=sum0;
				q1[tail]=sum1;
				sum0=0;sum1=0;
				if (a[i]==0) sum0++;
				if (a[i]==1) sum1++;
				while (1<tail){
					tmp=q1[tail]/(q0[tail]+q1[tail]);
					tmp1=q1[tail-1]/(q0[tail-1]+q1[tail-1]);
					if (tmp1>tmp) {
						q0[tail-1]+=q0[tail];
						q1[tail-1]+=q1[tail];
						tail--;
					}
					else {break;} 
				}
			} 
			else{
				if (a[i]==0) sum0++;
				if (a[i]==1) sum1++;
			} 
			//cout<<i<<" "<<sum0 << " "<<sum1<<endl;
		}
		rep(i,1,tail){	
			tmp=q1[i]/(q0[i]+q1[i]);
			//cout<<q0[i]<<" "<<q1[i]<<endl;
			//printf("%.6lf\n",tmp);
			ans+=(1-tmp)*(1-tmp)*q1[i]+tmp*tmp*q0[i];
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}

