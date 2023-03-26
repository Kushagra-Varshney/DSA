#include<bits/stdc++.h>
using namespace std;

void removeOCC(string &s, string &part)
{
    int found = s.find(part);
    if(found != string::npos)
    {
        string left = s.substr(0,found);
        string right = s.substr(found+part.size(), s.size());
        s = left + right;

        removeOCC(s,part);
    }
    else{
        return;
    }
}

int main()
{
   string s = "daabcbaabcbc";
   string part = "abc";
   removeOCC(s,part);
   cout<<s;

 return 0;
}