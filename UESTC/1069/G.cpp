#include <cstdio>
#include <stack>
using std::stack;

const int N = 200000 + 10;

int n, h[N], w[N];
int now = 0;
stack<int> st;
int f[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d%d", &x, &h[i]);
		w[i] = w[i-1] + x;
	}
	st.push(0); h[0] = h[n+1] = -1;
	for(int i = 1; i <= n+1; i++)
	{
		while(h[i] < h[st.top()])
		{
			int idx = st.top(); st.pop();
			f[idx] = now - w[st.top()];
		}
		st.push(i);
		now = w[i];
	}
	//for(int i = 1; i <= n; i++) printf("%d ", f[i]);
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(f[i] * h[i] > res) res = f[i] * h[i];
	printf("%d\n", res);
	return 0;
}
