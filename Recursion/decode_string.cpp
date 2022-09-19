//https://leetcode.com/problems/decode-string/
#include<iostream>
using namespace std;

string decodeString(string& s, int& i)
{
   string result;
   while(i < s.length() && s[i] != ']')
   {
       if(isdigit(s[i]))
       {
          int k = 0;
          while(i < s.length() && isdigit(s[i]))
           k = k*10 + s[i++] - '0';
         i++;

         string r = decodeString(s,i); 
         while(k--)
          result += r;

         i++; 
       }
      else {
         result += s[i++];
      }
   }
  return result;

}


int main()
{
   string s = "3[a]2[b]";
   int index = 0;

   cout<<decodeString(s,index);

   return 0;
}