#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using std::string;
using std::map;

int n, m;
char tmp[100];
string cap[10010][20];
map<string, int> hash[20];

void Read()
{
	scanf("%d%d", &n, &m);
	fgets(tmp, 90, stdin);
	for(int i = 1; i <= n; i++)
	{
		fgets(tmp, 90, stdin);
		int j = -1, len = 0;
		for(int cnt = 1; cnt <= m; cnt++)
		{
			cap[i][cnt] = "";
			for(j++; tmp[j]!=',' && tmp[j]!='\n' && tmp[j]; j++)
				cap[i][cnt] += tmp[j];
			//puts(cap[i][cnt].c_str());
		}
	}
}

bool Solve()
{
	for(int l = 1; l <= m; l++)
	for(int r = l+1; r <= m; r++)
		for(int u = 1; u <= n; u++)
		for(int d = u+1; d <= n; d++)
			if(cap[u][l] == cap[d][l] && cap[u][r] == cap[d][r])
			{
				puts("NO");
				printf("%d %d\n%d %d\n", u, d, l, r);
				return 0;
			}
	return 1;
}

int main()
{
	Read();
	if(Solve()) puts("YES");;
	return 0;
}
