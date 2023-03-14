//leetcode 767
#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i=0; i<s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }

        //find the most frequent character
        char mostFrequentChar;
        int maxFrequency = -1;
        for(int i=0; i<26; i++)
        {
            if(hash[i] > maxFrequency)
             {maxFrequency = hash[i];
             mostFrequentChar = i + 'a';}
        }

        int index = 0;

        while(maxFrequency > 0 && index < s.size())
        {
            s[index] = mostFrequentChar;
            maxFrequency--;
            index += 2;
        }

        if(maxFrequency != 0)
         return "";

        hash[mostFrequentChar - 'a'] = 0;

        //place remaining characters

        for(int i=0; i<26; i++)
        {
            while(hash[i] > 0)
            {
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }

        return s;
    }

int main()
{
  

 return 0;
}