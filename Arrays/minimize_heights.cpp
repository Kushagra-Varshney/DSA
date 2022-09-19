//Minimize the Heights to find Minimum diff
//Compulsory to Add or Sub k from all values
#include<iostream>
#include<algorithm>
using namespace std;

int minHeight(int arr[], int n, int k)
 {
   sort(arr, arr+n);
   int minEle ,maxEle;
   int diff = arr[n-1] - arr[0];

   for(int i=1; i<n; i++)
    {
        if(arr[i]>=k)
         {
             minEle = min(arr[0]+k, arr[i]-k);
             maxEle = max(arr[n-1]-k, arr[i-1] + k);
         }
       diff = min(diff, maxEle - minEle);  
    }

    return diff;
 }


int main()
{
  int n,k;
  cout<<"Enter Size and k->";
  cin>>n>>k;

  int a[n];

  for(int i=0; i<n; i++)
   cin>>a[i];

  cout<<"Minimum Difference is->"<<minHeight(a,n,k); 
  
  return 0;

}
