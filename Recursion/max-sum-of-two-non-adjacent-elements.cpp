//find maximum sum bw non adjacent elements
//find a subsequence with maximum sum of non adjacent elements
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int i, int sum, int& maxi)
{
    if(i >= arr.size())
    {
        maxi = max(sum,maxi);
        return;
    }

    //include
    solve(arr, i+2, sum+arr[i], maxi);

    //exclude
    solve(arr, i+1, sum, maxi);
}

int main()
{
  vector<int> arr = {2,1,4,9};
  arr = {1,2,3,1,3,5,8,1,9};
  int sum = 0, maxi = INT_MIN, i = 0;

  solve(arr,i,sum,maxi);
  cout<<"maximum sum is: "<<maxi;

 return 0;
}