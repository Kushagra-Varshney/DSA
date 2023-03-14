#include<bits/stdc++.h>
using namespace std;

vector<int> twoPtrApproach(vector<int> arr, int k, int x)
    {
         //approach 1: two pointer approach

        int h = arr.size()-1;
        int l = 0;

        while(h - l >= k)
        {
            if(x - arr[l] > arr[h] - x)
             l++;
            else
             h--; 
        }

        vector<int> ans;

        // for(int i = l; i <= h; i++)
        //  {
        //      ans.push_back(arr[i]);
        //  }

         return vector<int>(arr.begin()+l, arr.begin()+h+1);
    }

int lowerbound(vector<int>& arr, int x)
 {
        int s = 0, e = arr.size()-1;
        
        int ans = e;

        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid] >= x)
            {
                ans = mid;
                e = mid-1;
            }
            else if(x > arr[mid])
             s = mid+1;
            else
             e = mid-1;
        }

        return ans;
 }

vector<int> bsApproach(vector<int> arr, int k , int x)
 {
        int h = lowerbound(arr,x);
        int l = h-1;

        cout<<l<<" "<<h;

        while(k--)
        {
            if(l < 0)
             h++;
            else if(h >= arr.size())
             l--;
            else if(x - arr[l] > arr[h] - x)
             h++;
            else
             l--;
        }

    return vector<int>(arr.begin()+l+1, arr.begin()+h);
 }

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    return bsApproach(arr, k, x);
}

int main()
{
  

 return 0;
}