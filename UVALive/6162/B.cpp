#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char sr[10],ss[10],st[10],se[10];
int flag,night,n,day,len,t1,t2,start,endt,len1,len2;
int Get(char *s){
	int d1,d2;
	d1=(s[0]-'0')*10+s[1]-'0';
	d2=(s[3]-'0')*10+s[4]-'0';
	//printf("%s %d %d\n",s,d1,d2);
	return(d1*60+d2);
}
int main(){
	int res;
	//freopen("test.in","r",stdin);
	while(cin>>n&&n){
		flag=res=day=night=0;
		for(int i=1;i<=n;i++){
			scanf("%s %s %s %s\n",&sr[0],&ss[0],&st[0],&se[0]);
			//printf("%s %s %s %s\n",sr,ss,st,se);
			t1=Get(sr);
			t2=Get(ss);
			start=Get(st);
			endt=Get(se);
			len=endt-start;	
			res+=len;
			//printf("%d %d %d %d\n",t1,t2,start,endt);
			//printf("%d %d\n",i,len);
			if(len>120){flag=1;continue;}
			if(start>=t2||endt<=t1){night+=len;continue;}
			if(endt<=t2&&start>=t1){day+=len;continue;}
			if(start<=t1&&endt>=t1&&endt<=t2){
				len1=t1-start;
				len2=len-len1;
				if(len1>=len2) night+=len;
					else day+=len2,night+=len1;
				continue;
			}
			if(start<=t1&&endt>=t2){
				len2=t2-t1;
				len1=len-len2;
				if(len1>=len2) night+=len;
					else day+=len2,night+=len1;
				continue;
			}
			if(start>=t1&&start<=t2&&endt>=t2){
				len2=t2-start;
				len1=len-len2;
				if(len1>=len2) night+=len;
					else day+=len2,night+=len1;
				continue;
			}
		}
		//printf("%d %d %d %d %d\n",flag,night,day,night+day,res);
		if(flag==0&&night>=600&&night+day>=50*60) printf("PASS\n");
			else printf("NON\n");
	}
	return 0;
}	
