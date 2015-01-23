#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using std::map;
using std::string;

map<string, int> P;
int m, n;
char X[60], Y[60];
string Xs, Ys;
struct Link{int y; double z; Link *next;}*head[510];
bool getAnswer, wrong;
double Answer;
int vis[510];
double calc[510];

void inLink(int x, int y, double z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x, double dis, int tar)
{
	if(wrong) return;
	if(vis[x] == 1) calc[x] = dis;
	if(vis[x] == 2)
	{
		if(dis < calc[x])
		{
			wrong = 1;
			return;
		}
	}
	if(x == tar)
	{
		getAnswer = 1;
		Answer = std::min(Answer, dis);
		return;
	}
	for(Link *p = head[x]; p; p = p->next)
	{
		if(vis[p->y] >= 2) continue;
		vis[p->y]++;
		dfs(p->y, dis + p->z, tar);
		vis[p->y]--;
		if(wrong) return;
	}
}

int solve()
{ // to see if : X (?) tb/ta * Y
	int ta, tb;
	scanf("%d%s", &ta, X); Xs = string(X);
	scanf("%d%s", &tb, Y); Ys = string(Y);
	
	getAnswer = 0; Answer = 1e20;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) calc[i] = 0;
	wrong = 0;
	dfs(P[Xs], log(1.0 * ta), P[Ys]);
	if(wrong) return 3;
	bool G1 = getAnswer;
	double res1 = exp(Answer);

	getAnswer = 0; Answer = 1e20;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) calc[i] = 0;
	wrong = 0;
	dfs(P[Ys], log(1.0 * tb), P[Xs]);
	if(wrong) return 3;
	bool G2 = getAnswer;
	double res2 = exp(Answer);
	
	if(G1 && G2)
	{
		double A1 = res1 / ta; // X <= res1/ta * Y
		double A2 = tb / res2; // X >= tb/res2 * Y
		//   ~ A2 ~ X ~ A1 ~
		if(fabs(A1 - A2) < 1e-7)
		{
			if(fabs(A1 - 1.0 * tb / ta) < 1e-7) return 0;
			if(A1 > 1.0 * tb / ta) return 1;
			return -1;
		}
		if(A1 < A2) return 3; // illegal
		if(A2 >= 1.0 * tb / ta) return 1;
		if(A1 <= 1.0 * tb / ta) return -1;
		return 2;
	}
	else if(G1) // X <= res1/ta * Y
	{
		double A1 = res1 / ta;
		// ~ X ~ A1 ~
		if(A1 <= 1.0 * tb / ta) return -1;
		return 2;
	}
	else if(G2) // X >= tb/res2 * Y
	{
		double A2 = tb / res2;
		// ~ A2 ~ X ~
		if(A2 >= 1.0 * tb / ta) return 1;
		return 2;
	}
	else return 2;
}

int main()
{
	while(scanf("%d", &m) == 1 && m)
	{
		P.clear(); n = 0;
		memset(head, 0, sizeof(head));
		for(int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%s", &a, X); Xs = string(X);
			scanf("%d%s", &b, Y); Ys = string(Y);
			if(!P[Xs]) P[Xs] = ++n;
			if(!P[Ys]) P[Ys] = ++n;
			inLink(P[Xs], P[Ys], log(1.0 * b / a));
		}
		int cc = solve();
		if(cc == -1) puts("<=");
		else if(cc == 0) puts("==");
		else if(cc == 1) puts(">=");
		else if(cc == 2) puts("UNAVAILABLE");
		else puts("INCONSISTENT");
	}
	return 0;
}
