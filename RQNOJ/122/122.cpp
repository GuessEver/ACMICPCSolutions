#include<iostream>
using namespace std;
 
string s[17]={"","hong","bai","qing","huang",
	"bai","qing","huang","hong","qing","huang",
	"hong","bai","huang","hong","bai","qing" };
 
int main()
{
	//freopen("rqn122.in","r",stdin);
	//freopen("rqn122.out","w",stdout);
	int n; scanf("%d",&n);
	n=(n-1)%16+1;
	cout<<s[n]<<endl;
	n=(((n-1)/4)%4+1)*4-3;
	for(int i=0;i<=3;i++)cout<<s[n+i]<<' ';
	return 0;
}
