#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int q;
string x, y;
map<string, string> hash;
map<string, bool> isnew;
string ans[1010], ans2[1010];
int n;

string find(string s)
{
	if(hash[s] == "") return s;
	return find(hash[s]);
}

int main()
{
	cin >> q;
	while(q--)
	{
		cin >> x >> y;
		hash[x] = y;
		if(!isnew[x]) ans[n++] = x;
		isnew[x] = isnew[y] = 1;
	}
	std::sort(ans, ans+n);
	//for(int i = 0; i < n; i++) cout << ans[i] << endl;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cnt++;
		ans2[i] = find(ans[i]);
	//	if(ans2[i] == hash[ans[i]])
	//	{
	//		cnt--;
	//		ans2[i] = "";
	//	}
	}
	cout << cnt << endl;
	for(int i = 0; i < n; i++)
	{
		if(ans2[i] == "") continue;
		cout << ans[i] << ' ' << ans2[i] << endl;
	}
	return 0;
}
