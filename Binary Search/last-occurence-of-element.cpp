#include<bits/stdc++.h>
using namespace std;

int findLastOccurence(vector<int> arr, int target)
{
    int s = 0, e = arr.size()-1, mid;

    mid = s + (e-s)/2;

    int ans = -1;

    while(s <= e)
    {
        if(arr[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > target)
        {
            e = mid -1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int main()
{
   vector<int> arr = {1,3,4,5,6,6,6,6,6,6,7,8,9};

   cout<<findLastOccurence(arr,6);

 return 0;
}