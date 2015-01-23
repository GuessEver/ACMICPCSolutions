#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10000];
int n,len;
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&s[0]);
		len=strlen(s);
		//printf("%d %d\n",len/2,len/2+1);
		if(s[len/2-1]==s[len/2]) printf("Do-it\n");
			else printf("Do-it-Not\n");
	}
	return 0;
}
