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
ll son[100100][26],c[30],d[30],x,n,m,num,ans,now,len;
char st[1100];
int main(){
	while (scanf("%lld%lld",&n,&m) && n!=0 && m!=0){
		clr(son,0);clr(c,0);num=0;
		rep (i,1,n){
			scanf("%s",st);
			len=strlen(st);
			now=0;
			rep(j,1,len){
				x=st[j-1]-'a';
				if (son[now][x]== 0) {son[now][x]= ++num;if (j!=1) c[x]++;}
				now=son[now][x];
			}	
			//c[st[0]-'a']--;
		}
		ans=num;
		num=0;clr(son,0);clr(d,0);
		rep(i,1,m){
			scanf("%s",st);
			len=strlen(st);
			now=0;
			for(ll j=len;j>=1;j--){
				x=st[j-1]-'a';
				if (son[now][x]==0) {son[now][x]=++num;if (j!=len) d[x]++;}
				now=son[now][x];
			}
			//d[st[len-1]-'a']--;
		}
		ans*=num;
		rep(i,0,25) ans-=c[i]*d[i];
		cout<<ans<<endl;
	}
	return 0;
}

