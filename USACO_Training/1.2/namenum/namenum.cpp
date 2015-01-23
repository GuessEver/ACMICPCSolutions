/*
ID: jiangzh15
TASK: namenum
LANG: C++
*/
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct node{string s,num;}a[5000];
int key['Z'+10];

void makemap()
{
    key['A']=key['B']=key['C']=2;
    key['D']=key['E']=key['F']=3;
    key['G']=key['H']=key['I']=4;
    key['J']=key['K']=key['L']=5;
    key['M']=key['N']=key['O']=6;
    key['P']=key['Q']=key['R']=key['S']=7;
    key['T']=key['U']=key['V']=8;
    key['W']=key['X']=key['Y']=key['Z']=9;
}

void readdict()
{
    ifstream fin("dict.txt");
    for(int i=1;i<=4617;i++) fin>>a[i].s;
    fin.close();
    for(int i=1;i<=4617;i++)
        for(int j=0;j<a[i].s.length();j++)
            a[i].num+=key[a[i].s[j]]+'0';
}

int main()
{
    makemap();
    readdict();
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    string tmp;
    cin>>tmp;
    bool flag=false;
    for(int i=1;i<=4617;i++)
        if(a[i].num==tmp)
            {cout<<a[i].s<<endl;flag=true;}
    if(!flag)cout<<"NONE"<<endl;
    return 0;
}
