//Find Square Root of a Number using Binary Search
#include<iostream>
using namespace std;

long long int sqrtInteger(int n)
{
   int s = 0;
   int e = n;
   long long int mid = s + (e-s)/2;
   long long int ans = -1;

   while(s<=e)
    {
        long long int square = mid*mid;

        if(square == n)
         {
             return mid;
         }

        if(square < n)
         {
             mid = ans;
             s = mid + 1;
         } 
        else 
         {
             e = mid - 1;
         }

       mid = s + (e-s)/2;  
    }

  return ans;

}

double morePrecision(int n, int precision, int tempSol)
{
   double factor = 1;
   double ans = tempSol;

   for(int i = 0; i<precision; i++)
    {
        factor = factor/10;

         for(double j = ans; j*j < n; j= j+factor)
          {
              ans = j;
              cout<<ans;
          }
    }

    return ans;
}

int main()
{
   int n;
   cout<<"Enter Number->";
   cin>>n;

   int tempSol = sqrtInteger(n);
   cout<<"Integer Root is"<<tempSol;
   cout<<"Square Root is "<<morePrecision(n, 3, tempSol);

   return 0;    
}