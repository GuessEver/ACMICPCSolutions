#include <cstdio>
#include <vector>
using std::vector;

char s[100100];
vector<int> v1, v2;

bool check(int x, int y)
{
	if(x < y) return x + 2 <= y;
	else return y + 2 <= x;
}

int main()
{
	scanf("%s", s);
	for(int i = 1; s[i]; i++)
	{
		if(s[i-1] == 'A' && s[i] == 'B') v1.push_back(i-1);
		if(s[i-1] == 'B' && s[i] == 'A') v2.push_back(i-1);
	}
	if(v1.size() > 0 && v2.size() > 0 && (check(*v1.begin(), *v2.begin()) || check(*v1.begin(), *(v2.end()-1))
			|| check(*(v1.end()-1), *v2.begin()) || check(*(v1.end()-1), *(v2.end()-1))))
		puts("YES");
	else puts("NO");
	return 0;
}
