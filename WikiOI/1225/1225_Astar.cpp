//Astar
#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

const string tar="123804765";
struct ND{
	string sta;int x0,y0;int f,g,h;
	bool operator < (const ND &a) const { return f>a.f; }
};
map<string,int> h;
priority_queue<ND> q;

int getf(ND &tmp)
{
	int res=0;
	for(int i=0;i<9;i++)
		if(tar[i]!=tmp.sta[i]) res++;
	tmp.h=res;
	return tmp.f=tmp.g+tmp.h;
}

bool expand(ND &now,ND &tmp,int k)
{
	tmp=now; tmp.g++;
	int x1=now.x0+dx[k];
	int y1=now.y0+dy[k];
	if(x1<0||x1>=3||y1<0||y1>=3) return 0;
	tmp.x0=x1; tmp.y0=y1;
	int pos1=now.x0*3+now.y0;
	int pos2=tmp.x0*3+tmp.y0;
	swap(tmp.sta[pos1],tmp.sta[pos2]);
	getf(tmp);
	return 1;
}

int Astar()
{
	while(!q.empty())
	{
		ND now=q.top(); q.pop();
		//cout<<now.sta<<' ';printf("%d %d %d\n",now.g,now.h,now.f);
		for(int k=0;k<4;k++)
		{
			ND tmp;
			if(!expand(now,tmp,k)) continue;
			if(tmp.sta==tar) return tmp.g;
			if(!h[tmp.sta])
			{
				h[tmp.sta]=1;
				q.push(tmp);
			}
		}
	}
	return -1;
}

int main()
{
	freopen("1225.in","r",stdin);
	freopen("1225.out","w",stdout);
	ND st; cin>>st.sta;
	for(int i=0;i<st.sta.length();i++)
		if(st.sta[i]=='0') st.x0=i/3,st.y0=i%3;
	st.g=0; getf(st);
	q.push(st);
	printf("%d\n",Astar());
	return 0;
}
