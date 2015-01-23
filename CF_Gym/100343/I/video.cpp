#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long LL;
double watch,d,ti,b,t,p,eps;
LL pp,l,r,ans1,ans,mid;
int main(){
	freopen("video.in","r",stdin);
	freopen("video.out","w",stdout);
	eps=1e-10;
	while(cin>>d>>b>>t>>p){
		watch=p*d/(b-d);
		ans=ceil(t/watch);
		pp=p*d;l=1;r=p*d;
		//cout<<ans<<endl;cout<<l<<" "<<r<<endl;
		while(l<r){
			mid=(l+r)>>1;
			watch=double(mid)/(b-d);
			ans1=ceil(t/watch);
			if(ans<ans1) l=mid+1;
				else{
					r=mid;
					pp=min(pp,mid);
				}
		}
		cout<<r<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
