#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using std::map;

const int N = 25000 + 10;

struct Nodeadd{
	double A, D;
}_add[2][N * 5 * 4];
struct Nodeval{
	double S;
}_val[2][N * 5 * 4];
struct Query{
	char op; int pos;
	int a[7][2];
}que[N];
int n, m;
map<int, int> hash;
int po[N * 5], P[N * 5];

void pushDown(Nodeval *val, Nodeadd *add, int p, int l, int mid, int r)
{
	add[p*2].A += add[p].A;
	add[p*2].D += add[p].D;
	val[p*2].S += (add[p].A + (add[p].A + (P[mid] - P[l]) * add[p].D)) * (P[mid] - P[l]) / 2;
	double tmpA = add[p].A + (P[mid] - P[l]) * add[p].D;
	add[p*2+1].A += tmpA;
	add[p*2+1].D += add[p].D;
	val[p*2+1].S += (tmpA + (tmpA + (P[r] - P[mid]) * add[p].D)) * (P[r] - P[mid]) / 2;
	add[p].A = add[p].D = 0.0;
}
void pushUp(Nodeval *val, Nodeadd *add, int p, int l, int mid, int r)
{
	val[p].S = val[p*2].S + val[p*2+1].S;
}

double query(Nodeval *val, Nodeadd *add, int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p].S;
	int mid = l + (r - l) / 2; double res = 0.0;
	pushDown(val, add, p, l, mid, r);
	if(a < mid) res += query(val, add, p*2, l, mid, a, b);
	if(b > mid) res += query(val, add, p*2+1, mid, r, a, b);
	pushUp(val, add, p, l, mid, r);
	return res;
}

void change(Nodeval *val, Nodeadd *add, int p, int l, int r, int a, int b, double A, double D)
{
	if(a <= l && b >= r)
	{
		add[p].A += A;
		add[p].D += D;
		val[p].S += (A + (A + (P[r] - P[l]) * D)) * (P[r] - P[l]) / 2;
		return;
	}
	int mid = l + (r - l) / 2;
	pushDown(val, add, p, l, mid, r);
	if(b <= mid) change(val, add, p*2, l, mid, a, b, A, D);
	else if(a >= mid) change(val, add, p*2+1, mid, r, a, b, A, D);
	else {
		change(val, add, p*2, l, mid, a, mid, A, D);
		change(val, add, p*2+1, mid, r, mid, b, A + (P[mid] - P[a]) * D, D);
	}
	pushUp(val, add, p, l, mid, r);
}

void Solve()
{
	memset(_val, 0, sizeof(_val));
	memset(_add, 0, sizeof(_add));
	for(int q = 1; q <= m; q++)
	{
		if(que[q].op == 'Q')
		{
			double down = query(_val[0], _add[0], 1, 1, n, que[q].a[0][0], que[q].a[0][1]);
			double up = query(_val[1], _add[1], 1, 1, n, que[q].a[0][0], que[q].a[0][1]);
			printf("%.3f\n", up - down);
		}
		else {
			for(int i = 2; i <= que[q].pos; i++)
			{ // line from point_1 to point_pos
				int x1 = que[q].a[i-1][0], y1 = que[q].a[i-1][1];
				int x2 = que[q].a[i][0], y2 = que[q].a[i][1];
				if(x1 == x2) continue;
				double A = y1, D = 1.0 * (y2 - y1) / (P[x2] - P[x1]);
				change(_val[0], _add[0], 1, 1, n, x1, x2, A, D);
			}
			for(int i = que[q].a[0][0]; i >= que[q].pos; i--)
			{
				int x1 = que[q].a[i+1][0], y1 = que[q].a[i+1][1];
				int x2 = que[q].a[i][0], y2 = que[q].a[i][1];
				if(x1 == x2) continue;
				double A = y1, D = 1.0 * (y2 - y1) / (P[x2] - P[x1]);
				change(_val[1], _add[1], 1, 1, n, x1, x2, A, D);
			}
		}
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &m); int cnt = 0;
		for(int i = 1; i <= m; i++)
		{
			scanf(" %c", &que[i].op);
			if(que[i].op == 'Q')
			{
				scanf("%d%d", &que[i].a[0][0], &que[i].a[0][1]);
				po[++cnt] = que[i].a[0][0];
				po[++cnt] = que[i].a[0][1];
			}
			else {
				scanf("%d", &que[i].a[0][0]);
				for(int j = 1; j <= que[i].a[0][0]; j++)
				{
					scanf("%d%d", &que[i].a[j][0], &que[i].a[j][1]);
					po[++cnt] = que[i].a[j][0];
					//po[++cnt] = que[i].a[j][1];
				}
			}
		}
		std::sort(po+1, po+1+cnt);
		hash.clear(); n = 0;
		for(int i = 1; i <= cnt; i++)
			if(!hash[po[i]])
			{
				hash[po[i]] = ++n;
				P[n] = po[i];
			}
		for(int i = 1; i <= m; i++)
		{
			if(que[i].op == 'Q')
			{
				que[i].a[0][0] = hash[que[i].a[0][0]];
				que[i].a[0][1] = hash[que[i].a[0][1]];
			}
			else {
				for(int j = 1; j <= que[i].a[0][0]; j++)
				{
					que[i].a[j][0] = hash[que[i].a[j][0]];
					//que[i].a[j][1] = hash[que[i].a[j][1]];
				}
			}
		}
		for(int i = 1; i <= m; i++)
			if(que[i].op == 'R')
			{
				int cnt = que[i].a[0][0] + 1;
				que[i].a[cnt][0] = que[i].a[1][0];
				que[i].a[cnt][1] = que[i].a[1][1];
			}
		for(int i = 1; i <= m; i++)
			if(que[i].op == 'R')
				for(int j = 1; j <= que[i].a[0][0]; j++)
					if(que[i].a[j+1][0] < que[i].a[j][0])
					{
						que[i].pos = j;
						break;
					}
		/*for(int i = 1; i <= m; i++)
		{
			if(que[i].op == 'Q') printf("Q %d %d\n", que[i].a[0][0], que[i].a[0][1]);
			else {
				printf("R %d\n", que[i].a[0][0]);
				for(int j = 1; j <= que[i].a[0][0]; j++)
					printf("%d %d ", que[i].a[j][0], que[i].a[j][1]);
				puts("");
			}
		}*/
		Solve();
	}
	return 0;
}
