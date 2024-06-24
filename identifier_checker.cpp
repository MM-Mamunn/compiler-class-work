#include<bits/stdc++.h>
using namespace std;

bool is_key(string s)
{
    const std::string cppKeywords[] =
    {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "constinit",
        "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype",
        "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
        "explicit", "export", "extern", "false", "float", "for", "friend", "goto",
        "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
        "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected",
        "public", "register", "reinterpret_cast", "requires", "return", "short",
        "signed", "sizeof", "static", "static_assert", "static_cast", "struct",
        "switch", "template", "this", "thread_local", "throw", "true", "try",
        "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual",
        "void", "volatile", "wchar_t", "while", "xor", "xor_eq", "main", "std" , "namespace", "using"
    };
    for(auto a : cppKeywords)
        if(a == s)
            return true;

    return false;
}
int main()
{

    string s = "";
    //cin >> s;
    bool f =true;
    if(s[0] != '_' && !isalpha(s[0]) )
        f=false;
    if(is_key(s))
        f= false;
    for(auto a : s)
        if( !isalnum(a) && a != '_' && a != '$')
        {
            f=false;
            break;
        }

    if(f)
        cout<<"Identifier\n";
    else
        cout<<"Not a Identifier\n";
    return 0;
}
