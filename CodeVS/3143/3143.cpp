#include<cstdio>
#include<algorithm>
const int N=100;

int n;
int L[N],R[N];

void first(int x)
{
	printf("%d ",x);
	if(L[x]) first(L[x]);
	if(R[x]) first(R[x]);
}
void mid(int x)
{
	if(L[x]) mid(L[x]);
	printf("%d ",x);
	if(R[x]) mid(R[x]);
}
void last(int x)
{
	if(L[x]) last(L[x]);
	if(R[x]) last(R[x]);
	printf("%d ",x);
}

int main()
{
	freopen("3143.in","r",stdin);
	freopen("3143.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]);
	
	first(1); puts("");
	mid(1); puts("");
	last(1); puts("");
	return 0;
}
