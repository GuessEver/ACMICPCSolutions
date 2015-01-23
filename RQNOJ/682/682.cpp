/*http://blog.csdn.net/jiangzh7
By Jiangzh*/
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
const int N=100000+10;

int m,limit,total;
int delta;
int S[N],A[N],L[N],R[N];
int root=0;

inline void init(int &p,int &k)
{
	S[p]=1;A[p]=k;
	L[p]=R[p]=0;
}

void rotate_left(int &x)
{
	int y=R[x];
	R[x]=L[y];
	L[y]=x;
	S[y]=S[x];
	S[x]=S[L[x]]+S[R[x]]+1;
	x=y;
}
void rotate_right(int &x)
{
	int y=L[x];
	L[x]=R[y];
	R[y]=x;
	S[y]=S[x];
	S[x]=S[L[x]]+S[R[x]]+1;
	x=y;
}

void maintain(int &p,bool flag)
{
	if(flag)
	{
		if(S[R[R[p]]]>S[L[p]]) rotate_left(p);
		else if(S[R[L[p]]]>S[L[p]])
		{
			rotate_right(R[p]);
			rotate_left(p);
		}
		else return;
	}
	else{
		if(S[L[L[p]]]>S[R[p]]) rotate_right(p);
		else if(S[L[R[p]]]>S[R[p]])
		{
			rotate_left(L[p]);
			rotate_right(p);
		}
		else return;
	}
	maintain(L[p],0);
	maintain(R[p],1);
	maintain(p,1);
	maintain(p,0);
}

void insert(int &p,int k)
{
	if(!p) {p=++total;init(p,k);}
	else{
		S[p]++;
		if(k<A[p]) insert(L[p],k);
		else insert(R[p],k);
		maintain(p,k>=A[p]);
	}
}

void del(int &p)
{
	if(!p) return;
	if(A[p]+delta<limit)
	{
		p=R[p];
		del(p);
	}
	else{
		del(L[p]);
		S[p]=S[L[p]]+S[R[p]]+1;
	}
}

int kth(int &p,int k)
{
	int tmp=S[L[p]]+1;
	if(k==tmp) return A[p];
	else if(k<tmp) return kth(L[p],k);
	else return kth(R[p],k-tmp);
}

void work()
{
	char op; int k;
	scanf("\n%c%d",&op,&k);
	if(op == 'I')//new
	{//if k<limit , the person is not the one who leaves!!!
		if(k>=limit) insert(root,k-delta);
	}
	else if(op=='A') //add
	{
		delta+=k;
	}
	else if(op=='S') //Sub
	{
		delta-=k;
		del(root);
	}
	else if(op == 'F') //kth_number
	{
		if(k>S[root]) printf("-1\n");
		else printf("%d\n",kth(root,S[root]-k+1)+delta);
	}
}

int main()
{
	scanf("%d%d",&m,&limit);
	while(m--) work();
	printf("%d\n",total-S[root]);
	ofstream fout("a.out");
	fout<<"12345";
	return 0;
}

