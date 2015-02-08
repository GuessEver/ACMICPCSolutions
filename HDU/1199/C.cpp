#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using std::map;

const int N = 2000 + 10;

struct Node{
	int x, y; char c;
	void Read() { scanf("%d%d %c", &x, &y, &c); }
}a[N];
map<int, int> hash;
int cor[7*N], P[7*N];
int n, m;
int col[N*30];
int ansL, ansR;
int L, R, last;

void change(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		col[p] = c;
		return;
	}
	if(col[p] != -1)
	{
		col[p*2] = col[p*2+1] = col[p];
		col[p] = -1;
	}
	int mid = (l + r) / 2;
	if(a <= mid) change(p*2, l, mid, a, b, c);
	if(b > mid) change(p*2+1, mid+1, r, a, b, c);
	if(col[p*2] == col[p*2+1] && col[p*2] != -1) col[p] = col[p*2];
}

void query(int p, int l, int r)
{
	if(col[p] == 1)
	{
		if(last == -1) 
		{
			L = l; R = r; 
			last = r;
			if(ansL == 0 || P[R] - P[L] + 1 > ansR - ansL + 1)
			{
				ansR = P[R];
				ansL = P[L];
			}
		}
		else{
			if(last + 1 == l)
			{
				R = r;
				last = r;
				if(ansL == 0 || P[R] - P[L] + 1 > ansR - ansL + 1)
				{
					ansR = P[R];
					ansL = P[L];
				}
			}
			else{
				L = l; R = r;
				last = r;
				if(ansL == 0 || P[R] - P[L] + 1 > ansR - ansL + 1)
				{
					ansR = P[R];
					ansL = P[L];
				}
			}
		}
		//printf("[%d, %d]\n", L, R);
	}
	if(col[p] != -1 || l == r) return;
	int mid = (l + r) / 2;
	query(p*2, l, mid);
	query(p*2+1, mid+1, r);
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		memset(col, 0, sizeof(col));
		hash.clear();
		memset(P, 0, sizeof(P));
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			a[i].Read();
			cor[++cnt] = a[i].x;
			if(a[i].x > 1) cor[++cnt] = a[i].x-1;
			if(a[i].x < 0x7fffffff) cor[++cnt] = a[i].x+1;
			cor[++cnt] = a[i].y;
			if(a[i].y > 1) cor[++cnt] = a[i].y-1;
			if(a[i].y < 0x7fffffff) cor[++cnt] = a[i].y+1;
		}
		std::sort(cor+1, cor+1+cnt);
		m = 0;
		for(int i = 1; i <= cnt; i++)
			if(!hash[cor[i]])
			{
				hash[cor[i]] = ++m;
				P[m] = cor[i];
			}
		for(int i = 1; i <= n; i++)
		{
			int k = (a[i].c == 'w' ? 1 : 0);
			change(1, 1, m, hash[a[i].x], hash[a[i].y], k);
		}
		//for(int i = 1; i <= 15; i++) printf("%3d ", col[i]);puts("");
		ansL = ansR = 0;
		L = R = 0; last = -1;
		query(1, 1, m);
		if(!ansL) puts("Oh, my god");
		else printf("%d %d\n", ansL, ansR);
	}
	return 0;
}
