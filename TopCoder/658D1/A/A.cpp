#include<bits/stdc++.h>
using namespace std;

class OddEvenTree {
public:
	vector <int> getTree(vector <string>);
};

int cap[100][100] = {0};
int f[100];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

vector <int> OddEvenTree::getTree(vector <string> x) {
	int n = x.size();
	vector<int> ans; ans.clear();
	for(int i = 0; i < n; i++) f[i] = i;
	memset(cap, 0x3f, sizeof(cap));
	for(int i = 0; i < n; i++) cap[i][i] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(x[i][j] == 'O')
			{
				if(getroot(i) == getroot(j)) continue;
				f[getroot(i)] = getroot(j);
				cap[i][j] = cap[j][i] = 1;
				ans.push_back(i);
				ans.push_back(j);
				//printf("%d %d\n", i, j);
			}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(cap[i][j] > cap[i][k] + cap[k][j])
					cap[i][j] = cap[i][k] + cap[k][j];
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) printf("%d ", cap[i][j]);
		puts("");
	}*/
	bool cc = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(cap[i][j] > 100) cc = 0;
			if(x[i][j] == 'O' && cap[i][j] % 2 == 0) cc = 0;
			if(x[i][j] == 'E' && cap[i][j] % 2 == 1) cc = 0;
			if(!cc) break;
		}
		if(!cc) break;
	}
	if(!cc) { ans.clear(); ans.push_back(-1); }
	return ans;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

