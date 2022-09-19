//Reverse a String using recursion
#include<iostream>
#include<string>
using namespace std;

//Can also reverse using 2 pointer approach
void rev(string s)
{
    if(s.length()==0)
     return;

    char ch = s[0];
    rev(s.substr(1));
    cout<<ch;

   
}

int main()
{
    string s = "ZrezalB";
    string reversed;
    rev(s);
}