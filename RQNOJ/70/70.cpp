#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

const string tar="123804765";
struct ND{string sta;int x0,y0;int step;};
queue<ND> q;
map<string,int> h;

bool expand(ND &now,ND &node,int k)
{
	node=now; node.step++;
	int x1=node.x0+dx[k];
	int y1=node.y0+dy[k];
	if(x1<0||x1>=3||y1<0||y1>=3) return 0;
	int pos1=node.x0*3+node.y0;
	int pos2=x1*3+y1;
	swap(node.sta[pos1],node.sta[pos2]);
	node.x0=x1; node.y0=y1;
	return 1;
}

void bfs()
{
	while(!q.empty())
	{
		ND now=q.front();q.pop();
		//cout<<now.sta<<' '<<now.x0<<' '<<now.y0<<endl;
		for(int k=0;k<4;k++)
		{
			ND tmp;
			if(!expand(now,tmp,k)) continue;
			if(tmp.sta==tar)
			{
				printf("%d\n",tmp.step);
				exit(0);
			}
			if(!h[tmp.sta])
			{
				h[tmp.sta]=1;
				q.push(tmp);
			}
		}
	}
}

int main()
{
	ND st; cin>>st.sta;
	st.step=0;
	for(int i=0;i<st.sta.length();i++)
		if(st.sta[i]=='0') st.x0=i/3,st.y0=i%3;
	q.push(st);
	bfs();
	printf("-1\n");
	return 0;
}
