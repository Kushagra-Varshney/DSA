#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr={0,1,0,0,0,1,1,1,1,0,0,0,1,0};

  int start = 0;
  int end = arr.size() - 1;

  while(start != end)
  {
     if(arr[start] == 0){
        start++;
     }
    else{
        swap(arr[start],arr[end]);
        end--;
    }
  }

  for(auto i: arr){
    cout<<i<<" ";
  }

 return 0;
}