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
int get(int x){
	if (x==0) return 1;
	int i=1<<29;
	while ((i & x)==0){i>>=1;}
	return 2*get(x^i);
}
int main(){
	int n;
	while (scanf("%d",&n)==1){
		cout<<get(n)<<endl;
	}
	return 0;
}

