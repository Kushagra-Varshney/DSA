#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1{1,2,3,4,5,6};

    vector<int> arr2{5,6,7,8,9};

    map<int,int> m1;

    for(int i=0; i<arr1.size(); i++)
    {
        m1.insert({arr1[i],i});
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        if(m1.find(arr2[i]) != m1.end())
        {
            cout<<arr2[i]<<" ";
        }
    }
    
 return 0;
}