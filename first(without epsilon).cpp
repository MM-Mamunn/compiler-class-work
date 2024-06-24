#include<bits/stdc++.h>
///under development, epsilon will not work 
using namespace std;
string s;
set<char>var;
map<char,vector<string>>m;
map<char,vector<char>>ans;

int check(string s, char ch)
{
    if(s[0] >= 'a' and s[0] <='z')
        ans[ch].push_back(s[0]);
    else
    {
        for(auto c :m[s[0]])
        {
            check(c,ch);
        }
    }
}
int32_t main()
{

    while(cin>>s and s!= "0")
    {
        char ch = s[0];
        var.insert(ch);
        s.erase(0,2);
        m[ch].push_back(s);
    }
    for(auto ch : var)
    {
        for(auto edge : m[ch])
        {
            check(edge,ch);
        }
    }

    for(auto ch:var)
    {
        cout<<"first of "<<ch<<" = ";
        for(auto c : ans[ch])
        {
            cout<<c<<' ';
        }
        cout<<endl;
    }
    return 0;
}


//S.ABc
//S.ghi
//S.jkl
//A.a
//A.b
//A.c
//B.b
//D.d
//0



