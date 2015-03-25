#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
string s[2200], ss;
int n;
int same[2200];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
	ios_base::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> s[i];
    cin >> ss;
    sort(s, s + n);
    for(i = 0; i < n; i++)
	{
		same[i] = 0;
		while(same[i] < s[i].length() && same[i] < ss.length() && s[i][same[i]] == ss[same[i]]) same[i]++;
	}
	int ans = ss.length();
	for(i = 0; i < ss.length(); i++)
	{
		int l = 0, r = n - 1;
		while(l < n && same[l] < i)l++;
		while(r >= 0 && same[r] < i)r--;
		for(j = l; j <= r; j++)
		{
			ans = min(ans, (int)(min(j - l, r - j) + ss.length() - same[j] + s[j].length() - same[j] + i + 1));
		}
	}
    cout << ans << endl;
    return 0;
}

