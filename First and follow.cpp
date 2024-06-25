#include<bits/stdc++.h>

using namespace std;
string s;
unordered_set<char>var;
vector<pair<string,char>>all;
map<char,vector<string>>m;
map<char,vector<char>>ans;
map<char,set<char>>ans2;
int f = 0,f2 =0;
int check(string s, char ch)
{

    if(s[0] >= 'a' and s[0] <='z')
    {
        ans[ch].push_back(s[0]);
        return 0;
    }
    else if(s[0] == '$')
        f = 1;
    else
    {

        for(auto c :m[s[0]])
        {
            check(c,ch);
        }
    }

}

int follow(char ch, string s,char ch2)
{
    if(s.size() == 1)
    {
        for(auto a : ans2[ch2])
            ans2[ch].insert(a);
        return 0;
    }
    if(s[1] >= 'a' and s[1]<='z')
    {
        ans2[ch].insert(s[1]);
        return 0;
    }
    for(auto a : ans[s[1]])
    {
        if(a == '$')
        {
            f2= 1;
            continue;
        }
        ans2[ch].insert(a);
    }
}
int32_t main()
{
    int fr =0;
    while(cin>>s and s!= "0")
    {
        char ch = s[0];
        var.insert(ch);
        s.erase(0,2);
        m[ch].push_back(s);
        all.push_back({s,ch});
        if(fr == 0)
        {
            fr = 1;
            ans2[ch].insert('#');
        }
    }
    for(auto ch : var)
    {
        for(auto edge : m[ch])
        {
            if(edge == "$")
                ans[ch].push_back('$');
            else
            {
                f = 0;
                check(edge, ch);
                while(f)
                {
                    f = 0;
                    if(edge.size() > 1)
                        edge.erase(0,1);
                    else
                    {
                        ans[ch].push_back('$');
                        break;
                    }

                    check(edge, ch);
                }
            }
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

    for(auto ch : var)
    {
        for(auto s : all)
        {
            for(int i = 0; i< s.first.size(); i++)
            {
                string temp = s.first;
                if(ch == temp[i])
                {
                    temp.erase(0,i);
                    f2 = 0;
                    follow(ch,temp,s.second);
                    while(f2)
                    {
                        f2 = 0;
                        temp.erase(0,1);
                        follow(ch,temp,s.second);
                    }
                }
            }
        }
    }
    for(auto ch:var)
    {
        cout<<"follow of "<<ch<<' ';
        for(auto a : ans2[ch])
            cout<<a<< ' ';
        cout<<endl;
    }

    return 0;
}

/*
let,
S->ABC
A->a|b|$
B->c|d|$
C->e|f|$
where $ = epsilon
then the input format is as follow

*/
//
//S.ABC
//A.a
//A.b
//A.$
//B.c
//B.d
//B.$
//C.e
//C.f
//C.$
//0

//testcase 2
//S.aSbS
//S.bSaS
//S.$
//0


