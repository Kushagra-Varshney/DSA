//Print the fibonacci upto the nth number using recursion
#include<iostream>
using namespace std;

int fibonacci(int num)
{
   //base case 
   if(num==0)
    return 0;
   if(num==1)
    return 1;

   int ans = fibonacci(num-1) + fibonacci(num-2);

   return ans;  
   
   
}

int main()
{
   int num = 8;

   cout<<num<<"th Fibonacci Number is:"<<fibonacci(num);

  return 0;  
}
