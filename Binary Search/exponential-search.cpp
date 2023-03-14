#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> arr, int s, int e, int target)
{
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        if(arr[mid] == target)
         return mid;
        else if(arr[mid] < target)
         s = mid+1;
        else
         e = mid-1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int exponentialSearch(vector<int> arr, int target)
{
    if(arr[0] == target)
     return 0;

    int i = 1;

    while(i < arr.size() && arr[i] < target)
    {
        i *= 2;
    }

    int minimum = (i <= arr.size()-1 ? i: arr.size()-1);

    int ans = bs(arr, i/2, minimum , target);

    return ans;
}

int main()
{
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  cout<<exponentialSearch(arr,7);

 return 0;
}