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
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
string st[30],st1[30];
ll n,l[30],a[30][30],f[21000][21];
int main(){
	while (cin>>n && n>0)	{
		for (ll i=1;i<=n;i++){
			cin>>st1[i];
			//l[i]=st[i].length();
		}
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=n;j++){
				if (i !=j ){
					if ((int)st1[i].find(st1[j]) != -1) {
						st1[j]="~";
					}
				}
			}
		}
		ll tmp=0;
		for (ll i=1;i<=n;i++){
			//cout<<st1[i]<<endl;
			if (st1[i]!="~"){
				st[++tmp]=st1[i];
				l[tmp]=st[tmp].length();
			//	cout<<tmp<<endl;
			}
		}
		n=tmp;
		//cout<<(ll)st[1].find(st[2])<<endl;
		clr(a,0);
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=n;j++){
				if (i != j) {
					for (ll k=l[i];k>=1;k--){
						ll p1,p2,tmp;
						p1=k;p2=1;tmp=0;
						while (p1<=l[i] && p2<=l[j]){
							//cout<<i<<" "<<j<<" "<<p1<<" "<<p2<<st[i][p1-1]<<" "<<st[j][p2-1]<<endl;
							if ( st[i][p1-1]==st[j][p2-1]) { tmp++;p1++;p2++;} else break;
						}
						if (tmp == l[i]-k+1){a[i][j]=tmp;}; 
					}
				}
			}
		}
		clr(f,10000);f[0][0]=0;
		for (ll i=1;i<=n;i++){f[1 << i-1][i]=l[i];};
		for (ll s=1;s<=(1<<n)-2;s++){

			for (ll k=1;k<=n;k++){ 
				if ( ((s & (1<<(k-1)))>0) && (f[s][k]<=2000)) {
					for (ll i=1;i<=n;i++){
						if ((s & (1<<i-1))== 0){
							ll tmp=s | (1<<i-1);
							f[tmp][i]=min(f[tmp][i],f[s][k]+l[i]-a[k][i]);
						}
					}
				}
			}
		}
		ll ans=10000;for (ll i=1;i<=n;i++) ans=min(ans,f[(1<<n)-1][i]);
		cout<<ans<<endl;
	}
}
