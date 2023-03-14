//leetcode 443
#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& s) {
        int index = 0, count = 1;
        char prev = s[0];

        for(int i =1; i<s.size(); i++)
        {
            if(s[i] == prev)
            {
                count++;
            }
            else
            {
                s[index++] = prev;
                if(count > 1)
                 {
                     int start = index;
                     while(count)
                     {
                         s[index++] = (count % 10) + '0';
                         count /= 10;
                     }

                     reverse(s.begin() + start, s.begin() + index); 
                     // reverse works till end-1 hence no need to -1
                 }

                 prev = s[i];
                 count = 1;
            }
        }

         s[index++] = prev;
        if(count > 1)
        {
            int start = index;
            while(count)
            {
                s[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }

        return index;
    }

int main()
{
  

 return 0;
}