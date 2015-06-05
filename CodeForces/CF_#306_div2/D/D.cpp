#include <cstdio>
#include <utility>
#include <vector>
using std::pair;
using std::vector;

int n;
vector<pair<int, int> > ans;
bool four;

void connect(int l, int r, int p)
{
	for(int i = l; i <= l + 1; i++)
		for(int j = i + 1; j <= r; j++)
			ans.push_back(std::make_pair(i, j));
	for(int i = l + 2; i <= r; i++)
	{
		for(int j = i + 1; j <= r; j++)
		{
			if(i + 2 == j) continue;
			if(!four && i == r - 1 && j == r) continue;
			ans.push_back(std::make_pair(i, j));
		}
		ans.push_back(std::make_pair(i, p));
	}
	for(int i = r - (four ? 5 : 3); i >= l + 2; i -= 4)
	{
		ans.push_back(std::make_pair(i, i + 2));
		ans.push_back(std::make_pair(i + 1, i + 3));
	}
}

int main()
{
	scanf("%d", &n);
	if(n % 2 == 0) { puts("NO"); return 0; }
	int part = (n + 1) / 2;
	four = ((n - 1) % 4 == 0);
	puts("YES");
	if(n == 1) printf("2 1\n1 2\n");
	else {
		connect(1, n + 1, n + 2);
		connect(1 + n + 2, n + 1 + n + 2, n + 2 + n + 2);
		ans.push_back(std::make_pair(n + 2, n + 2 + n + 2));
		printf("%d %d\n", n + 2 + n + 2, (int)ans.size());
		for(vector<pair<int, int> >::iterator it = ans.begin(); it < ans.end(); it++)
			printf("%d %d\n", (*it).first, (*it).second);
	}
	return 0;
}
