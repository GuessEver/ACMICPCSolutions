#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL a,b,c,d,x,y,i;
void Print(LL x,LL y){
	printf("%lld foom%s and %lld foob%s for a twob!\n",x,x==1?"":"s",y,y==1?"":"s");
	return;
}
LL ExGcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1;y=0;return a;
	}else{
		LL d=ExGcd(b,a%b,x,y);
		LL k=x;
		x=y;y=k-a/b*y;
		return(d);
	}
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>a>>b>>c&&(a||b||c)){
		d=ExGcd(a,b,x,y);
		if(c%d){printf("Unquibable!\n");continue;}
		b/=d;c/=d;
		x=(((x%b)*(c%b))%b+b)%b;
		c*=d;b*=d;
		y=(c-a*x)/b;
		if(y<0){printf("Unquibable!\n");continue;}
			else Print(x,y);
	}
	return 0;
}
