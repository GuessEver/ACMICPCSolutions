#include<cstdio>

int main()
{
	int x;
	scanf("%d",&x);
	bool flag=true;
	if(x<2) flag=false;
	for(int i=2;i<x;i++)
	    if(x%i==0) {flag=false;break;}
	if(flag) printf("\\t\n");
	else printf("\\n\n");
	return 0;
}
