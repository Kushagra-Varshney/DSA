#include<bits/stdc++.h>
using namespace std;

bool inRange(char x)
    {
        if(x == 'a' || x == 'e' || x == 'i' || 
        x == 'o' || x == 'u' || x == 'A' || 
        x == 'E' || x == 'I' || x == 'O' || x == 'U')
         return true;
        else
         return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int low = 0; int high = n-1;

        while(low < high)
        {
            if(inRange(s[low]) && inRange(s[high])) // can also use STL function isalpha()
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            if(!inRange(s[low]))
             low ++;
            if(!inRange(s[high]))
             high--;
        }

        return s;
    }

int main()
{
  

 return 0;
}