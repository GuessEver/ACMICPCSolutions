#include <cstdio>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int cnt = 0;
	while(++cnt)
	{
		Sleep(1000);
		system("mk");
		system("financial");
		system("c");
		ifstream fin1("financial.out");
		ifstream fin2("financial2.out");
		int n1, n2;
		fin1 >> n1; fin2 >> n2;
		if(n1 == n2)
		{
			printf("%d Accepted....Maybe\n", cnt);
			continue;
		}
		puts("Wrong");
		getchar();
		break;
	}
	return 0;
}
