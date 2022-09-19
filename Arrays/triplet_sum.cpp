#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          vector<vector<int>> ans; 
          int start  = 0; int end = nums.size()-1;
          int s = 0;
        
        while(start < end)
        {
            if(nums[start] + nums[end] < s)
            {
                for(int i = start+1; i<end; i++)
                    if(nums[start] + nums[end] + nums[i] == s)
                    { 
                        vector<int> temp;
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        temp.push_back(nums[i]);
                        cout<<nums[start]<<" "<<nums[end]<<" "<<nums[i]<<endl;
                        ans.push_back(temp);
                    }
                start ++;        
            }
            else
              end -- ;            
                
        
        }
      return ans;  
}

int main()
{
   vector<int> nums;
   for(int i = 0; i<6; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

   threeSum(nums);

  return 0;  
}