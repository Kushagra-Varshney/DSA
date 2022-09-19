#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter Size of Arrays->";
    cin>>n>>m;

    int a1[n],a2[n];
    set<int> s;

    for(int i=0; i<n; i++)
     { 
       cin>>a1[i];
       s.insert(a1[i]);
     } 
     
    for(int i=0; i<m; i++)
       cin>>a2[i];

    cout<<"Intersection is - ";

    for(int i=0; i<m; i++)
     if(s.find(a2[i]) != s.end())
      cout<<a2[i]<<" ";  

 return 0;
}