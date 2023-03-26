#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void choriKarlo(vector<int> nums, int currentHouse, int currentAmount, int& maxAmount)
    {
        //base case
        if(currentHouse >= nums.size())
         {
             maxAmount = max(maxAmount,currentAmount);
             return;
         }

        //include currentHouse
        choriKarlo(nums, currentHouse+2, currentAmount + nums[currentHouse], maxAmount);

        //exclude currentHouse
        choriKarlo(nums, currentHouse+1, currentAmount, maxAmount);
    }

    int rob(vector<int>& nums) {
        int currentHouse = 0;
        int maxAmount = 0;
        int currentAmount = 0;

        choriKarlo(nums, currentHouse, currentAmount, maxAmount);

        return maxAmount;
    }
};

int main()
{
  

 return 0;
}