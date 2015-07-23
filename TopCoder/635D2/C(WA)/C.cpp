#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class LonglongestPathTree {
public:
	long long getLength(vector <int>, vector <int>, vector <int>);
};

const int N = 2000 + 10;

int n;
struct Link{int y, z; Link *next;}*head[N];

void inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

long long tmpdeep, tmpx;
int U;
int vis[N];

void dfs(int x, int deep)
{
	if(vis[x] == U) return;
	vis[x] = U;
	if(deep > tmpdeep)
	{
		tmpx = x;
		tmpdeep = deep;
	}
	for(Link *p = head[x]; p; p = p -> next)
	{
		dfs(p -> y, deep + p->z);
	}
}

int far[N];

long long LonglongestPathTree::getLength(vector <int> A, vector <int> B, vector <int> L) {
	n = A.size() + 1;
	for(int i = 0; i < n; i++)
	{
		inLink(A[i], B[i], L[i]);
		inLink(B[i], A[i], L[i]);
	}
	U = 1;
	for(int i = 0; i < n; i++)
	{
		tmpdeep = 0; tmpx = i; U++;
		dfs(i, 0);
		far[i] = tmpx;
	}
	//printf("%d %d\n", tmpx, tmpdeep);
	int k = -1, maxx = 0;
	U++;
	for(int i = 0; i < n; i++) if(vis[far[i]] != U)
	{
		tmpdeep = 0; tmpx = far[i];
		dfs(far[i], 0);
		if(tmpdeep > maxx)
		{
			maxx = tmpdeep;
			k = far[i];
		}
	}
	//printf("k = %d\n", k);
	long long res = 0;
	++U;
	tmpdeep = 0;
	dfs(k, 0);
	//printf("%d\n", tmpdeep);
	res += tmpdeep;
	U++;
	int kk, maxy = 0;
	for(int i = 0; i < n; i++)
		if(far[i] != k && vis[far[i]] != U)
		{
			tmpdeep = 0; tmpx = far[i];
			dfs(far[i], 0);
			if(tmpdeep > maxy)
			{
				maxy = tmpdeep;
				kk = far[i];
			}
		}
	--U;
	tmpdeep = 0;
	dfs(kk, 0);
	res += tmpdeep;
	//printf("%d\n", res);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
