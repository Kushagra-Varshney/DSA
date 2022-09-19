//Fixed Point is when Index = Value in sorted array
#include<iostream>
using namespace std;

int main()
{
   int n;
   cout<<"Enter Size->";
   cin>>n;

   int a[n];
   
   for(int i=0; i<n; i++)
    cin>>a[i];

   int start = 0, end = n-1,mid;

   while(start<=end)
    {
        mid = start + (end-start)/2;
        if(a[mid]==mid)
         {
           cout<<mid;
           break;
         }  
        else 
         if(a[mid]>mid)
          end = mid - 1;
        else 
          start = mid +1;  
    }  

   return 0; 
}

