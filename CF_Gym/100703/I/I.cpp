#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 200010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
struct node
{
    int no, value, c;
} course[NUM];
int n, m[220], M;
bool operator < (node a, node b)
{
    if(a.value == b.value)
        return a.no < b.no;
    return a.value < b.value;
}
int cnt[220];
int l, r, resn, ans[220];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &m[i]);
    for(i = 1, M = 0; i <= n; i++)
    {
        for(j = 1; j <= m[i]; j++, M++)
        {
            scanf("%d", &course[M].value);
            course[M].no = i;
            course[M].c = j;
        }
    }
    sort(course, course + M);
    k = 0;
    l = 0, r = 0, resn = INF;
    for(i = 0, j = 0; j < M;)
	{
		for(; k < n && j < M; j++)
		{
			if(cnt[course[j].no] == 0)
				k++;
			cnt[course[j].no]++;
		}
		for(; k == n && i < M; i++)
		{
			if(course[j-1].value - course[i].value < resn)
			{
				resn = course[j - 1].value - course[i].value;
				l = i;
				r = j;
			}
			cnt[course[i].no]--;
			if(cnt[course[i].no] == 0)
				k--;
		}
	}
	for(l; l < r; l++)
		ans[course[l].no] =course[l].c;
	printf("%d\n", resn);
	for(i = 1; i <= n; i++)
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}
