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
const int NUM = 1010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
struct node
{
    int sum, one, zero, id;
    void in(int i)
    {
        scanf("%d%d", &zero, &one);
        sum = zero + one;
        id = i;
    }
} p[NUM],stk[NUM];
int top;
int ch[NUM][2];
string ans[NUM];
bool operator < (node a, node b)
{
    if(a.sum == b.sum)
        return a.one < b.one;
    return a.sum < b.sum;
}
int n, ansn;
int num;
bool solve()
{
    priority_queue<node> que;
    node t1, t2;
    int i;
    num = n;
    for(i = 0; i < n; i++)
        que.push(p[i]);
    ansn = -1;
    while(true)
    {
        t1 = que.top();
        que.pop();
        // cout << t1.id << ' ' << t1.sum << ' ' << t1.one << endl;
        if(que.empty())
        {
            ansn = t1.id;
            return t1.sum == 0;
        }
        t2 = que.top();
        que.pop();
        top = 0;
        while(t1.sum == t2.sum && t1.one == t2.one)
		{
			stk[top++] = t2;
			if(que.empty()) return false;
			t2 = que.top();
			que.pop();
		}
        //cout << t2.id << ' ' << t2.sum << ' ' << t2.one << endl;
        if(t1.sum != t2.sum || t1.one != t2.one + 1)
            return false;
        p[num].sum = t1.sum - 1;
        p[num].one = t1.one - 1;
        p[num].zero = t1.zero;
        p[num].id = num;
        ch[num][0] = t2.id;
        ch[num][1] = t1.id;
        while(top)
		{
			que.push(stk[--top]);
		}
        que.push(p[num++]);
    }
}
void getAns()
{
    ans[ansn] = "";
    queue<int> que;
    que.push(ansn);
    while(!que.empty())
    {
        int fa = que.front();
        que.pop();
        int u = ch[fa][0];
        if(u != -1)
        {
            que.push(u);
            ans[u] = ans[fa] + '0';
        }
        u = ch[fa][1];
        if(u != -1)
        {
            que.push(u);
            ans[u] = ans[fa] + '1';
        }
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
#endif
    int i, j;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            return 0;
        for(i = 0; i < n; i++)
            p[i].in(i);
        memset(ch, -1, sizeof(ch));
        if(solve())
        {
            puts("Yes");
            getAns();
            for(i = 0; i < n; i++)
                printf("%s\n", ans[i].c_str());
        }
        else
            puts("No");
    }
    return 0;
}
