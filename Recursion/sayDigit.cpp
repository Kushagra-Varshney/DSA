//Print the input Number in words acc to the digit
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

void sayDigit(int num, unordered_map<int,string> m)
{
   if(num <=0)
    return;
   
   int digit = num%10;
   num = num / 10;
   sayDigit(num, m);
   cout<<m[digit]<<" "; 
}

int main()
{
   unordered_map<int, string> m;
   m.insert({1,"One"});
   m.insert({2,"Two"});
   m.insert({3,"Three"});
   m.insert({4,"Four"});
   m.insert({5,"Five"});
   m.insert({6,"Six"});
   m.insert({7,"Seven"});
   m.insert({8,"Eight"});
   m.insert({9,"Nine"});
   m.insert({0,"Zero"});

   int num = 111;

   sayDigit(num, m);

  return 0;
}
