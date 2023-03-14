#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int arr[], int n, int k, long long sol)
    {
        long long boardLen = 0; // x unit of board takes x unit of time to paint
        int painterCount = 1;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > sol)
            {
                return false;
            }
            
            if(boardLen + arr[i] > sol)
            {
                painterCount++;
                boardLen = arr[i];
                
                if(painterCount > k)
                 return false;
            }
            else
             boardLen += arr[i];
        }
        
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long s = 0;
        long long e = 0;
        for(int i = 0; i < n; i++)
         e += arr[i];
         
        long long ans = -1;
        
        while(s <= e)
        {
            long long mid = s + (e-s)/2;
            
            if(isPossibleSolution(arr, n, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
             s = mid + 1;
        }
        
        return ans;
    }

int main()
{
  

 return 0;
}