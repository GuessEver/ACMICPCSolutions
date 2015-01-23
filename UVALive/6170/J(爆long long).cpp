#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL a,b,c,d,x,y,i;
void Print(LL x,LL y){
	printf("%lld foom%c and %lld foob%c for a twob!\n",x,x==1?0:'s',y,y==1?0:'s');
	return;
}
void ExGcd(LL a,LL b){
	if(!b){
		x=1;y=0;return;
	}else{
		ExGcd(b,a%b);
		LL k=x;
		x=y;y=k-a/b*y;
	}
}
LL Gcd(LL a,LL b){
	return(b==0?a:Gcd(b,a%b));
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>a>>b>>c&&(a||b||c)){
		//printf("%lld %lld %lld\n",a,b,c);
		if(!c){Print(0,0);continue;}
		if(a==0||b==0){
			if(a==0&&b==0){printf("Unquibable!\n");continue;}
			if(a==0){
				if(c%b) printf("Unquibable!\n");
					else Print(0,c/b);
				}else{
					if(c%a) printf("Unquibable!\n");
						else Print(c/a,0);
					
					}
			continue;
		}
		d=Gcd(a,b);
		if(c%d){printf("Unquibable!\n");continue;}
		a/=d;b/=d;c/=d;
		ExGcd(a,b);
	//	x*=c;y*=c;
		if(x<0){
			i=(-x)/b;
			if(x+i*b<0) i++;
			x+=i*b;y-=i*a;
		}
		if(y<0){
			i=(-y)/a;
			if(y+i*a<0) i++;
			y+=i*a;x-=i*b;
		}
		if(x<0||y<0){printf("Unquibable!\n");continue;}
		i=x/b;
		if(x-b*i<0) i++;
		y+=a*i;
		x-=b*i;
		x*=c;y*=c;
		if(x>=0&&y>=0) Print(x,y);
			else printf("Unquibable!\n");
	}
	return 0;
}
