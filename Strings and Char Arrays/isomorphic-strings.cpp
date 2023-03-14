//leetcode 205
#include<bits/stdc++.h>
using namespace std;

 bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; //stores the mapping from 's' to 't'
        bool isMapped[256] = {0}; //stores if a character has been mapped or not

        for(int i=0; i<s.length(); i++)
        {
            if(hash[s[i]] == 0 && isMapped[t[i]] == 0)
            {
                hash[s[i]] = t[i];
                isMapped[t[i]] = 1;
            }
        }

        for(int i=0; i<s.length(); i++)
        {
            if(char(hash[s[i]]) != t[i])
             return false;
        }

        return true;
    }

int main()
{
  

 return 0;
}