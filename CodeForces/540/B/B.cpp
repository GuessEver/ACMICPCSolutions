#include <cstdio>
#include <algorithm>
#include <vector>
using std::vector;

int n, k, p, x, y, a[1010];
vector<int> v;
int bigger = 0, smaller = 0, same = 0, sum = 0;

int main()
{
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > y) bigger++;
		else if(a[i] == y) same++;
		else smaller++;
		sum += a[i];
	}
	int mid = (n + 1) / 2;
	if(smaller >= mid) puts("-1");
	else {
		if(!(same + bigger)) { v.push_back(y); same++; sum += y; }
		while(smaller + same < mid - 1 && smaller + same + bigger < n)
		{
			v.push_back(1); smaller++; sum += 1;
		}
		while(smaller + same + bigger < n)
		{
			if(smaller < mid - 1)
			{
				v.push_back(1); smaller++; sum += 1;
			}
			else{
				v.push_back(y); same++; sum += y;
			}
		}
		if(sum > x || k + v.size() > n || !(smaller + same >= mid || same + bigger >= mid)) puts("-1");
		else for(vector<int>::iterator it = v.begin(); it < v.end(); it++)
			printf("%d ", *it);
	}
	return 0;
}
