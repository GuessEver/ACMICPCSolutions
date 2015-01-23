/*
ID: jiangzh15
TASK: calfflac
LANG: C++
*/
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

string s;
struct node{char ch;int num;}a[20010];
int len[20010];

int main()
{
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");
    string temp;
    while(getline(fin,temp)) {s+=temp;s+="\n";}
    int c=0;
    int i,j;
    for(i=0;i<s.length();i++)
        if(isalpha(s[i]))
        {
            a[c].ch=toupper(s[i]);
            a[c].num=i;
            c++;
        }
    int l,r,sum,maxx=0;
    for(i=0;i<c;i++)//枚举中间点
    {
        j=1;sum=1;
        while(i-j>=0 && i+j<c)//处理奇数情况
        {
            if(a[i-j].ch==a[i+j].ch)
            {
                sum+=2;
                if(sum>maxx)
                {
                    maxx=sum;
                    l=i-j;r=i+j;
                }
            }
            else break;
            j++;
        }
        j=0;sum=0;
        while(i-j>=0 && i+j+1<c)//处理偶数情况
        {
            if(a[i-j].ch==a[i+j+1].ch)
            {
                sum+=2;
                if(sum>maxx)
                {
                    maxx=sum;
                    l=i-j;r=i+j+1;
                }
            }
            else break;
            j++;
        }
    }
    fout<<maxx<<endl;
    for(i=a[l].num;i<=a[r].num;i++) fout<<s[i];
    fout<<endl;
    fin.close();fout.close();
}
