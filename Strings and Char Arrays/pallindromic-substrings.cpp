//VVIP Question
#include<bits/stdc++.h>
using namespace std;

    int expandAroundIndex(string s, int left, int right)
    {
        int count = 0;
        while(left >= 0 && right <s.length() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for(int i=0; i<s.length(); i++)
        {
            //odd length substring
            int oddKaAns = expandAroundIndex(s,i,i);
            count += oddKaAns;

            //even length substring
            int evenKaAns = expandAroundIndex(s,i,i+1);
            count += evenKaAns; 
        }

        return count;
    }

int main()
{
  

 return 0;
}