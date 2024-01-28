#include <bits/stdc++.h>
using namespace std;
int main()

{
    string s;
    int f =0;
    fstream read("myy.txt",ios:: in);
    ofstream out("output.cpp");
    int multiline =0;
    while (getline (read, s))
    {
        // Output the text from the file
        int len = s.size(),newline=0;
        int slash =0;
        string ans ="";
            for(int i =0; i<len; i++)
            {
                if(s[i]=='"')
                {
                    if(f==1)
                        f=0;
                    else
                        f=1;
                    out.put(s[i]);
                    continue;
                }
                if(s[i] == '/' && i+1<len && s[i+1]=='/' && f== 0 )
                {
                    slash =2;
                    continue;
                }
                if(s[i] == '/' && i+1<len && s[i+1]=='*' && f== 0 && multiline ==0)
                {
                    multiline=1;
                    continue;
                }
                if(multiline && s[i] == '*' && i+1<len && s[i+1]=='/' )
                {
                    multiline=0;
                    i+=1;
                    continue;
                }
                if(multiline)
                    continue;
                if(slash != 2)
                {
                    newline=1;
                    out.put(s[i]);
                }
            }
        if(newline || len == 0)
            out.put('\n');
    }
    read.close();
    out.close();
cout<<"Successfull:: Check the output file\n";

}
