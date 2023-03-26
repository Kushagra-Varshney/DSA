//to create target sum using minimum number of elements
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int target)
{
    //base case
    if(target == 0)
    {
        return 0;
    }

    if(target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i=0; i<v.size(); i++)
    {
        int ans = solve(v, target - v[i]);
        if(ans != INT_MAX)
         mini = min(ans+1,mini); // ans+1 because ans contains result of making target-v[i] but not target
    }

    return mini;
}

int main()
{
  vector<int> v = {1,2};
  int target = 5;

  int ans = solve(v,target);

  cout<<ans;

 return 0;
}