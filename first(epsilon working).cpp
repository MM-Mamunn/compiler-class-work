#include<bits/stdc++.h>

using namespace std;
string s;
unordered_set<char>var;
map<char,vector<string>>m;
map<char,vector<char>>ans;
int f = 0;
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


