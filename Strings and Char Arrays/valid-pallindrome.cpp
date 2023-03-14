//leetcode 680
#include<bits/stdc++.h>
using namespace std;

    bool checkPallindrome(string s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
             return false;
            else
            {
                i++; j--;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        
        int i = 0, j = s.length()-1;

        while(i <= j)
        {
            if(s[i] != s[j])
            {
            //remove i once then rmemove j once (check krke aao ki kya htane ke baad paalindrome bnega?)
                return checkPallindrome(s, i+1, j) || checkPallindrome(s, i, j-1);
            }
            else
            {
                i++; j--;
            }
        }

        return true;
    }

int main()
{
  

 return 0;
}