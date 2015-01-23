#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;

string start,end;
string a[10],b[10];
int n;
set<string> hash;
struct node{string s;int step;};
queue<node> q;

void work(node tt,int k)
{
	string s=tt.s;
	int pos=0;
	string tmp=s;
	while(1)
	{
		//find all positions
			int p=tmp.find(a[k]);
			pos+=p+1;
			tmp.erase(0,p+1);
			if(p==tmp.npos) break;
			//printf("%d ",pos);
			//cout<<s<<endl;
		//-----end
		//change
			pos--;
			node res;res.s="";res.step=tt.step+1;
			for(int i=0;i<pos;i++) res.s+=s[i];
			res.s+=b[k];
			for(int i=pos+a[k].length();i<s.length();i++) res.s+=s[i];
			//cout<<res.s<<endl;
			pos++;
		//-----end
		if(res.s==end)
		{
			printf("%d\n",res.step);
			exit(0);
		}
		if(res.step==11) continue;
		if(!hash.count(res.s))
		{
			hash.insert(res.s);
			q.push(res);
		}
	}
}

int main()
{
	cin>>start>>end;
	if(start==end) {printf("0");exit(0);}
	while(cin>>a[++n]>>b[n]);n--;
	node sta;sta.s=start;sta.step=0;
	q.push(sta);
	while(!q.empty())
	{
		node t=q.front();q.pop();
		for(int i=1;i<=n;i++)
		{
			work(t,i);
		}
	}
	printf("NO ANSWER!");
	return 0;
}

