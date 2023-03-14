//leetcode 1910
#include<bits/stdc++.h>
using namespace std;

 string removeOccurrences(string s, string part) {
        
        while(s.find(part) != string::npos)
        {
            int index = s.find(part);
            s.erase(index, part.length());
        }

        return s;
    }

int main()
{
  

 return 0;
}