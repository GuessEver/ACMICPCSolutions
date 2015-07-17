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
	ll a,b,c,d;
}p1[100100],p2[101000];
bool cmp(Node x,Node y){
	if (x.c==y.c) return x.d<y.d;
	return x.c<y.c;
}
ll n,hash[100100];
int main(){
	cin>>n;
	//rep(i,1,n){ cin>>p1[i].a>>p2[i].a;if (p1[i].a<=p2[i].a) {cout<<"Redemption"<<endl;return 0;} p1[i].b=p2[i].b=i;}
	rep(i,1,n) scanf("%d",&p1[i].a);
	rep(i,1,n) scanf("%d",&p2[i].a);
	rep(i,1,n) {p1[i].b=p2[i].b=i;p1[i].c=p2[i].c=p1[i].a;p1[i].d=p2[i].d=p2[i].a;}
	rep(i,1,n) if (p1[i].a<=p2[i].a) {cout<<"Redemption"<<endl;return 0;}; 
	sort(p1+1,p1+1+n,cmp);
	sort(p2+1,p2+1+n,cmp);
	ll i=1,tmp=0;
	clr(hash,0);
	rep(j,1,n){
		tmp+=p2[j].a;
		while (hash[p1[i].b]==1 && i<=n) i++;
		//cout<<j<<" "<<i<<" "<<" "<<tmp<<" "<<p1[i].a<<endl;
		if (i>n) {cout<<"Dire victory"<<endl;return 0;}
		if (p1[i].a<=tmp) {cout<<"Redemption"<<endl;return 0;}
		hash[p2[j].b]=1;
	}
	cout<<"Dire victory"<<endl;
	return 0;
}
