#include<cstdio>

int main()
{
	for(int i=1;i<=7;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x+y>8) {printf("%d",i);return 0;}
	}
	printf("0");
	return 0;
}
