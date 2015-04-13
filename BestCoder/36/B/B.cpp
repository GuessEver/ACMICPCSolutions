#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

const int N = 1000000 + 10;

int n, m;
int a[N], val[N], hei[N];
int L, R;

inline int nextInt()
{
	char ch; int res = 0;
	while(!isdigit(ch = getchar())) if(ch == EOF) return 0;
	do res = ((res << 1) + (res << 3)) + (ch - '0');
	while(isdigit(ch = getchar()));
	return res;
}

int find(int height)
{
	int low = L, high = R;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(hei[mid] > height) high = mid - 1;
		else if(hei[mid] < height) low = mid + 1;
		else return mid;
	}
	return L;
}

int main()
{
	while((n = nextInt()) && (m = nextInt()))
	{
		for(int i = 1; i <= n; i++) a[i] = nextInt();
		std::sort(a+1, a+1+n);
		L = 1; R = 0; // [L, R)
		for(int i = 1; i <= n; i++)
		{
			if(i == 1 || a[i] != a[i-1])
			{
				hei[++R] = a[i];
				val[R] = 0;
			}
			val[R]++;
		}
		for(int i = 1; i <= m; i++)
		{
			int x = nextInt();
			int k = find(x);
			if(hei[k] == x)
			{
				printf("%d\n", val[k]);
				val[k] = 0;
			}
			else printf("%d\n", 0);
		}
	}
	return 0;
}
