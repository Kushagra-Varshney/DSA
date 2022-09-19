#include<iostream>
#include<set>
using namespace std;

int main()
{
     int n,m;
     cout<<"Enter Sizes of Arrays->";
     cin>>n>>m;

     int a1[n],a2[m];
     set<int> s;

     for(int i=0; i<n; i++)
      {
        cin>>a1[i];
        s.insert(a1[i]);
      }  

     for(int i=0; i<m; i++)
      {
        cin>>a2[i];
        s.insert(a2[i]);
      }  
     cout<<"Union of Arrays is->";
     for(auto i : s)
      cout<<i<<" ";
 return 0;
}