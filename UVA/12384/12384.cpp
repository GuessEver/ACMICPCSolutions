#include <cstdio>
#include <cstring>
#include <stack>
using std::stack;

const int N = 2000000;

int hash[N+10];
int cnt = 0;
int pri[200000];

void make_prime_list()
{
	for(int i = 2; i <= N; i++)
	{
		if(!hash[i]) pri[++cnt] = i;
		for(int j = 1; j*i <= N; j++)
			hash[j*i] = 1;
	}
}

int n, m;
int a[100000+10];
int L[100000+10];
stack<int> st;

int main()
{
	make_prime_list();
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) a[i] = pri[i] % m;
		a[0] = m;
		int res = 0;
		/*for(int i = 1; i <= n; i++)
			for(int j = i; j >= 1; j--)
			{
				if(a[j] > a[i]) break;
				res++;
			}*/
		st.push(0);
		for(int i = 1; i <= n; i++)
		{
			while(a[i] >= a[st.top()]) st.pop();
			L[i] = i - st.top();
			st.push(i);
			if(a[i] > a[i-1] && L[i-1]+1 > L[i])
				L[i] = L[i-1] + 1;
			//printf("%d ", L[i]);
			res = (res + L[i] % m) % m;
		}
		printf("%d\n", res % m);
	}
	return 0;
}
