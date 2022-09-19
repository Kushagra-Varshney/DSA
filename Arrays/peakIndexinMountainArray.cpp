#include<iostream>
using namespace std;

int peakIndex(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e)
     {
         if(arr[mid]<arr[mid+1])
          s = mid + 1;
         else
          e = mid;

         mid = s + (e-s)/2; 
     }

   return s;  
}


int main()
{
   int arr[] = {26,69,100,99,79,78,67,36,26,19};

   cout<<"Peak Index is:"<<peakIndex(arr,10);

   return 0;   
}