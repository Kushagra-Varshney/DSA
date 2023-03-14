//gareeb approach - count occurences and create array
#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> arr={0,1,2,0,1,2,0,0,1,1,2,2,0,1};

   int start = 0;
   int end = arr.size()-1;
   int mid = 0;

   while(mid <= end)
   {
        if(arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else
        {
            swap(arr[mid],arr[end]);
            end--;
        }
   }

   for(auto i: arr){
    cout<<i<<" ";
   }

 return 0;
}