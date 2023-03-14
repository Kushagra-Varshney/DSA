//assumption - negative number need not be in order
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {-1,1,2,3,4,5,65,-5,6,6,-3,-2,-1};

  int start = 0;
  int end = arr.size()-1;

  while(start < end)
  {
     if(arr[start] < 0)
     {
        start++;
     }
     else if(arr[end] > 0)
     {
        end --;
     }
     else
     {
        swap(arr[start], arr[end]);
     }
  } 

  for(auto i: arr){
    cout<<i<<" ";
   }

 return 0;
}