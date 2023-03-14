#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int n, int k, vector<int> stalls, int sol)
{
        int cowsPlaced = 1;
        int lastPlacedAt = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - lastPlacedAt >= sol)
             {
                 cowsPlaced++;
                 lastPlacedAt = stalls[i];
                 
                 if(cowsPlaced >= k)
                  return true;
             }
             else
              continue;
        }
        
        return false;
}

int solve(int n, int k, vector<int> &stalls) 
{
        sort(stalls.begin(), stalls.end());
        
        int s = 0;
        int e = stalls[stalls.size()-1] - stalls[0];
        int ans = -1;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(isPossibleSolution(n, k, stalls, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
             e = mid - 1;
        }
        
        return ans;
}

int main()
{
  

 return 0;
}