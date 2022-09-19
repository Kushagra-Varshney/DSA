//https://leetcode.com/problems/permutations/
#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> nums,vector<vector<int>>& ans, int index)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums,ans,index+1);
            //backtrack
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            int index =0 ;
            
        solve(nums,ans,index);
        
        return ans;
    }

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    permute(nums);

    return 0;
}