#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(
    vector<long long int>trees, int requirement,long long int cutAt)
{
    long long int currentWood = 0;

    for(int i = 0; i < trees.size(); i++)
    {
        if(trees[i] >= cutAt)
        {
            currentWood += (trees[i]-cutAt);
        }
    }

    if(currentWood >= requirement)
     return true;
    else
     return false;
}

long long int solve(vector<long long int>& trees, int requirement)
{
    long long int s = 0;
    long long int e = *max_element(trees.begin(),trees.end());
    long long int ans = -1;

    while(s <= e)
    {
        long long int mid = s + (e-s)/2;
        if(isPossibleSolution(trees, requirement, mid))
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
  vector<long long int> trees = {4, 42, 40, 26, 46};

  cout<<"Solution is: "<<solve(trees,20);

 return 0;
}