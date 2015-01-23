#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
const int N=40000+10;
int n,m,K;
struct node{
	char s[10];
	node(){memset(s,0,sizeof(s));}
}tt[N];
deque<node> deQ;
stack<node> st;
bool flag=0;

void pop()
{
	if(!flag)
	{
		node t=deQ.front();
		deQ.pop_front();
		st.push(t);
	}
	else{
		node t=deQ.back();
		deQ.pop_back();
		st.push(t);
	}
}

void push(node a)
{
	if(!flag)
	{
		if(deQ.size()==K)
		{
			node t=deQ.front(); 
			deQ.pop_front();
			st.push(t);
		}
		deQ.push_back(a);
	}
	else{
		if(deQ.size()==K)
		{
			node t=deQ.back();
			deQ.pop_back();
			st.push(t);
		}
		deQ.push_front(a);
	}
}

void work()
{
	for(int i=1;i<=n;i++) scanf("%s",tt[i].s);
	for(int i=n;i>=1;i--) push(tt[i]);
	while(m--)
	{
		char s[50]; memset(s,0,sizeof(s));
		scanf("%s",s); int len=strlen(s);
		if(s[0]=='A')
		{
			node name; int j=0,k=0;
			while(j<len && s[j]!='(') j++;
			j++;
			while(s[j]!=')') name.s[k++]=s[j++];
			push(name);
		}
		else flag=!flag;
	}
	while(!deQ.empty()) pop();
	while(!st.empty())
	{
		node t=st.top();st.pop();
		puts(t.s);
	}
}

int main()
{
	freopen("1831.in","r",stdin);
	freopen("1831.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&K)==3)
	{
		work();
		printf("\n");
	}
	return 0;
}
