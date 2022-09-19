//https://www.spoj.com/problems/PRATA/
#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[], int n, int pratas, int mid)
{
    int sum = 0;
    for(int i=0; i<n; i++)
     {
        int time = mid;
        int count = 0, k = 1;

        while(time>0)
         {
            time -= k*arr[i];
            if(time>=0)
             {
               count ++;
               k++;
             }             
         }
        sum += count; 
     }
    if(sum<pratas)
     return false;

  return true;    
}

int prata(int arr[], int n, int pratas)
{
    sort(arr, arr+n);
    int s = 0;
    int e = arr[0] * (pratas*(pratas+1))/2;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(isPossible(arr,n,pratas,mid))
         {
             ans = mid;
             e = mid - 1;
         }
         else 
             s = mid + 1;

        mid = s + (e-s)/2;     
    }

    return ans;
}

int main()
{
   int arr[] = {1,2,3,4};
   cout<<"Possible Solution:"<<prata(arr,4,10);

  return 0; 
}
