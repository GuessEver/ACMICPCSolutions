#include <cstdio>
#include <vector>
using std::vector;

char s[100], t[100];
vector<int> ans;

int main()
{
	scanf("%s", s);
	while(1)
	{
		int len = 0;
		for(int i = 0; s[i]; i++)
		{
			if(s[i] > '0') t[len++] = '1';
			else t[len++] = '0';
		}
		t[len] = 0;
		int tmp; sscanf(t, "%d", &tmp);
		if(tmp == 0) break;
		ans.push_back(tmp);
		for(int i = 0; s[i]; i++) s[i] -= (t[i] - '0');
	}
	printf("%d\n", (int)ans.size());
	for(vector<int>::iterator it = ans.begin(); it < ans.end(); it++)
		printf("%d ", *it);
	return 0;
}
