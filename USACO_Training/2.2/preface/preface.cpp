/*
TASK: preface
LANG: C++
ID: jiangzh15
*/
#include<cstdio>
#include<string>
using std::string;
const string num[20][20]={
	{"","I","II","III","IV","V","VI","VII","VIII","IX"},//¸ö
	{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},//Ê®
	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},//°Ù
	{"","M","MM","MMM","","","","","",""}//Ç§
};

int n;
int Cnt['Z'+10];

void calc(int x)
{
	int pos=0;
	string s="";
	while(x)
	{
		int a=x%10; x/=10;
		s+=num[pos][a];
		pos++;
	}
	for(int i=0;i<s.length();i++)
		Cnt[s[i]]++;
}

int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		calc(i);
	}
	if(Cnt['I']) printf("I %d\n",Cnt['I']);
	if(Cnt['V']) printf("V %d\n",Cnt['V']);
	if(Cnt['X']) printf("X %d\n",Cnt['X']);
	if(Cnt['L']) printf("L %d\n",Cnt['L']);
	if(Cnt['C']) printf("C %d\n",Cnt['C']);
	if(Cnt['D']) printf("D %d\n",Cnt['D']);
	if(Cnt['M']) printf("M %d\n",Cnt['M']);
}
