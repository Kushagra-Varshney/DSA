//https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
using namespace std;

int findRepeating(vector<int> arr)
{
    unordered_map<int,int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        if(m.find(arr[i]) == m.end())
        {
            m.insert({arr[i],1});
        }
        else{
            m[arr[i]]++;
        }
    }

    for (auto i: m) // i is a key value pair
    {
        if(i.second > 1)
         return i.first;
    }
    
   return -1;
}

int main()
{
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};

    cout<<"First Repeating Element is: "<<findRepeating(arr);

 return 0;
}       