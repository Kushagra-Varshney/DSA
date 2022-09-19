//Find Last Occurence of an element 
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
 {
     int start = 0, end = n-1;
     int mid;
     int ans = -1;
     
     while(start<=end)
      {
          mid = start + (end-start)/2; // mid = s/2 + e/2
          if(arr[mid] == target)
           {
               ans = mid;
               start = mid + 1;

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
     return ans; 
   
 }


int main()
{
  int n,t;
  cout<<"Enter Size and Target->";
  cin>>n>>t;

  int a[n];
  for(int i=0; i<n; i++)
   cin>>a[i]; 

  cout<<binarySearch(a,n,t); 

  return 0;
}