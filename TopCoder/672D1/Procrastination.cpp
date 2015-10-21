#line 2 "Procrastination.cpp"
#include<bits/stdc++.h>
using namespace std;
class Procrastination { 
public:
	map<long long, vector<long long> > val;
	long long get(long long x, long long pre)
	{
		if(val.find(x) == val.end())
		{
			vector<long long> v; v.clear();
			for(long long i = 2; i * i <= x; i++) if(x % i == 0)
			{
				v.push_back(i);
				v.push_back(x / i);
			}
			std::sort(v.begin(), v.end());
			v.resize(std::unique(v.begin(), v.end()) - v.begin());
			val[x] = v;
		}
		for(vector<long long>::iterator it = val[x].begin(); it != val[x].end(); it++)
			if(*it > pre) return *it;
		return 3 * x;
	}
	long long findFinalAssignee(long long n) { 
		long long factor = 1;
		while(1)
		{
			long long factor1 = get(n - 1, factor);
			long long factor2 = get(n, factor);
			if(std::min(factor1, factor2) * 2 > n) return n;
			if(factor1 < factor2) n--;
			else n++;
			factor = std::min(factor1, factor2);
		}
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 3LL; verify_case(0, Arg1, findFinalAssignee(Arg0)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 11LL; verify_case(1, Arg1, findFinalAssignee(Arg0)); }
	void test_case_2() { long long Arg0 = 20LL; long long Arg1 = 20LL; verify_case(2, Arg1, findFinalAssignee(Arg0)); }
	void test_case_3() { long long Arg0 = 196248LL; long long Arg1 = 196259LL; verify_case(3, Arg1, findFinalAssignee(Arg0)); }
	void test_case_4() { long long Arg0 = 5587021440LL; long long Arg1 = 5587021440LL; verify_case(4, Arg1, findFinalAssignee(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE
int main()
{
	Procrastination ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
