#include <cstdio>
#include <string>
#include <algorithm>
using std::min;
using std::max;
using std::string;

const int N = 100000 + 10;

char tmp[100];
string A[N], B[N];
int n;

bool solve()
{
	string last = "";
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		if(last == "")
		{
			last = min(A[x], B[x]);
		}
		else{
			if(last < A[x] && last < B[x])
			{
				last = min(A[x], B[x]);
			}
			else if(last < A[x] || last < B[x])
			{
				last = max(A[x], B[x]);
			}
			else return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", tmp);
		A[i].assign(tmp);
		scanf("%s", tmp);
		B[i].assign(tmp);
	}
	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}
