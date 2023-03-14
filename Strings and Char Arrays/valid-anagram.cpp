#include<bits/stdc++.h>
using namespace std;

bool checkAnagram1(string s, string t)
{
    if(t.length() > s.length())
        return false;

        int n = t.length();
        for(int i =0; i<n; i++)
        {
            if(s.find(t[i]) != string::npos)
            {
                int index = s.find(t[i]);
                s.erase(index,1);
            }
        }

        if(s.length() == 0)
         return  true;
        else
         return false;

}

bool checkAnagram2(string s, string t)
{
     int freqTable[256] = {0}; //index of array indicates the ascii valueof character

        for(int i=0; i<s.length(); i++)
        {
            freqTable[s[i]]++;
        }

        for(int i=0; i<t.length(); i++)
        {
            freqTable[t[i]]--;
        }

        for(int i=0; i<256; i++)
        {
            if(freqTable[i] != 0)
             return false;
        }

        return true;
}


int main()
{
  string s = "anagram";
  string t = "nagaram";

  cout<<checkAnagram1(s,t)<<endl<<checkAnagram2(s,t);

 return 0;
}