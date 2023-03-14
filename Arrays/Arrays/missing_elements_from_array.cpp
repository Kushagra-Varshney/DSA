//Given an array with duplicates find the missing element
#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int index = arr[i] -1;

        if(arr[index] < 0)
         continue;

        arr[index] *= -1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > 0)
         return i+1;
    }
    
    
}

int main()
{
   vector<int> arr = {3,1,3,4,1,1,1,1,1};

   cout<<"Missing Number is: "<<findMissing(arr);

 return 0;
}