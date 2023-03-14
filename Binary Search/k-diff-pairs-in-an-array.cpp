//leetcode 532
#include<bits/stdc++.h>
using namespace std;

int bSearch(vector<int> nums, int s, int value)
    {
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s <= e)
        {
            if(nums[mid] == value)
             return mid;
            else if(nums[mid] < value)
             s = mid +1;
            else
             e = mid-1;

            mid = s + (e-s)/2;
        }

        return -1;
    }

int kDiffPairs1(vector<int> nums, int k)
{
            //approach1: Two Pointer Approach

        sort(nums.begin(), nums.end());
        set<pair<int,int>> ans;
        int i = 0, j = 1;

        while(j < nums.size())
        {
            int diff = nums[j] - nums[i];

            if(diff == k)
            {
                ans.insert({nums[i],nums[j]});
                i++; j++;
            }
            else if(diff < k)
            {
                j++;
            }
            else
            {
                i++;
            }

            if(i == j)
                j++;
        }

        return ans.size();
}

int kDiffPairs2(vector<int> nums, int k)
{
    sort(nums.begin(), nums.end());
        set<pair<int,int>> ans;

        for(int i=0; i<nums.size(); i++)
        {
            if(bSearch(nums,i+1,nums[i]+k) != -1)
            {
                ans.insert({nums[i], nums[i]+k});
            }
        }

        return ans.size();
}

int main()
{
  

 return 0;
}