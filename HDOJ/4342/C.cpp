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
int main(){
	ll ttt,n;cin>>ttt;
	while (ttt--){
		cin>>n;
		ll cnt=0,ans=0,i=0,tmp=0,sum=0,key;
		while (cnt<n){
			i++;
			tmp=(i+1)*(i+1)-(i*i)-1;
			if (cnt+tmp>=n) {tmp=n-cnt;key=(i*i)+tmp;sum+=(tmp+1)*i;break;}
			cnt+=tmp;sum+=((i+1)*(i+1)-(i*i))*i;
			//cout<<i<<" "<<tmp<<" "<<sum<<endl;
		}
		cout<<key<<" "<<sum<<endl;
	}
	return 0;
}

