#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<algorithm>
using std::string;
using std::sort;

struct node{int a,n;}a[100];

bool cmp(node a,node b)
{
	return a.n<b.n;
}

void mkdata()
{
	for(int i=1;i<=9;i++) a[i].a=i-1,a[i].n=rand();
	sort(a+1,a+10,cmp);
	for(int i=1;i<=9;i++) printf("%d",a[i].a);
	puts("");
}

int main()
{
	srand(time(0));
	mkdata();
}
