//Check if a String is pallindrome using recursion
#include<iostream>
using namespace std;

bool checkPallindrome(string s, int i, int j)
{
    if(i>j)
     return true;
     
    if(s[i] != s[j])
     return false;
    else
     checkPallindrome(s,i+1,j-1); 

}

int main()
{
    string s = "helleh";
    int i = 0;
    int j = s.length()-1;

    bool ans = checkPallindrome(s,i,j);

    cout<<ans;

   return 0; 
}