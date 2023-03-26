#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string s,string currString, int index)
{
    if(index >= s.length())
    {
        cout<<currString<<endl;
        return;
    }

    //exclude
    printSubsequences(s,currString,index+1);
    //include
    printSubsequences(s,currString+s[index],index+1);
      
}

int main()
{
   string curr = ""; int index = 0;
   printSubsequences("abc",curr,index);

 return 0;
}