#include<iostream>
using namespace std;

void binarySearch(int arr[], int n, int target)
 {
     int start = 0, end = n-1;
     int mid;
     bool flag = false;
     
     while(start<=end)
      {
          mid = start + (end-start)/2; // mid = s/2 + e/2
          if(arr[mid] == target)
           {
               cout<<"Element Found at Position "<<mid+1;
               flag = true;
               break;
           }
          else if(target < arr[mid])
           {
               end = mid -1;
           }
          else
           {
               start = mid + 1;
           } 
      }
   if(flag == false)
    cout<<"Element Not Found";

 }


int main()
{
  int n,t;
  cout<<"Enter Size and Target->";
  cin>>n>>t;

  int a[n];
  for(int i=0; i<n; i++)
   cin>>a[i]; 

  binarySearch(a,n,t); 

  return 0;
}











