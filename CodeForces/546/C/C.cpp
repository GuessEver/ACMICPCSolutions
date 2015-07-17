#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <utility>
using std::string;
using std::set;
using std::pair;

int n;
typedef pair<string, string> pir;
set<pir> l;

string Read()
{
	int x; scanf("%d", &x);
	string res = "";
	for(int i = 1; i <= x; i++)
	{
		int t; scanf("%d", &t);
		char ch = t + '0';
		res += ch;
	}
	return res;
}

void solve(string A, string B, int ans)
{
	//printf("%s %s %d\n", A.c_str(), B.c_str(), ans);
	if(A == "" || B == "")
	{
		printf("%d %d\n", ans, A == "" ? 2 : 1);
		exit(0);
	}
	pir tmp = std::make_pair(A, B);
	if(l.find(tmp) != l.end())
	{
		puts("-1");
		exit(0);
	}
	l.insert(tmp);
	if(A[0] < B[0])
	{
		B += A[0]; B += B[0];
	}
	else {
		A += B[0]; A += A[0];
	}
	A.erase(0, 1);
	B.erase(0, 1);
	solve(A, B, ans + 1);
}

int main()
{
	scanf("%d", &n);
	string A = Read();
	string B = Read();
	solve(A, B, 0);
	return 0;
}
