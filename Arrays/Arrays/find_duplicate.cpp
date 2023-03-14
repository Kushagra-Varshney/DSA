#include<bits/stdc++.h>
using namespace std;

int findDuplicateNoModify(vector<int> arr)
{
    while(arr[0] != arr[arr[0]])
    {
        swap(arr[0], arr[arr[0]]);
    }

    return arr[0];
}

//but this solution modifies the array
int findDuplicate(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        //taking number as a index
        int index = abs(arr[i]);
        if(arr[index] < 0)
        {
            return index;
        }

        //marking with negative value
        arr[index] *= -1;
    }

    return -1;
}

int main()
{
   vector<int> arr = {3,1,3,4,2};

   cout<<"Duplicate Element is:"<<findDuplicateNoModify(arr);


 return 0;
}