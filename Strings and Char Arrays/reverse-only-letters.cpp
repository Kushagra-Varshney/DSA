#include<bits/stdc++.h>
using namespace std;

bool inRange(char ch)
    {
        if(ch <= 'z' && ch >= 'a' || ch <= 'Z' && ch >= 'A')
         return true;
        else
         return false;
    }

    string reverseOnlyLetters(string s) {
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