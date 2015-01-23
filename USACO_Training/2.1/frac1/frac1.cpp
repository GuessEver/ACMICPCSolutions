/*
LANG: C++
PROG: frac1
ID: jiangzh15
*/
#include<cstdio>
#include<queue>
using std::priority_queue;

int n;
struct Node{
	int a,b;
	bool operator < (const Node &t) const
	{
		return (double)a/b > (double)t.a/t.b;
	}
	bool operator == (Node tt)
	{
		return a==tt.a && b==tt.b;
	}
};
priority_queue<Node> Q;

int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }

int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	Node one,zero;
	one=(Node){1,1}; Q.push(one);
	zero=(Node){0,1}; Q.push(zero);
	for(int i=1;i<=n;i++)//·ÖÄ¸
		for(int j=1;j<i;j++)//·Ö×Ó
		{
			int tt=gcd(i,j);
			Node t; t=(Node){j/tt,i/tt};
			Q.push(t);
		}
	Node last=Q.top(); Q.pop();
	printf("%d/%d\n",last.a,last.b);
	while(!Q.empty())
	{
		Node now=Q.top(); Q.pop();
		if(now==last) continue;
		last=now;
		printf("%d/%d\n",last.a,last.b);
	}
	return 0;
}
