#include<cstdio>

int a,b,c,d,ans=0;

int main()
{
	//freopen("rqn227.in","r",stdin);
	//freopen("rqn227.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	//总共六种情况 从优到劣依次枚举 
	while(a>0 && d>0) {ans++;a--;d--;}//1,4
	while(b>0 && c>0) {ans++;b--;c--;}//2,3
	while(a>1 && c>0) {ans++;a-=2;c--;}//1,1,3
	while(a>0 && b>1) {ans++;a--;b-=2;}//1,2,2
	while(a>2 && b>0) {ans++;a-=3;b--;}//1,1,1,2
	while(a>4) {ans++;a-=5;}//1,1,1,1,1
	printf("%d",ans);
	return 0;
}

