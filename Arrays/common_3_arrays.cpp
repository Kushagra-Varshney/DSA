//find common element in 3 sorted arrays
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Size->";
    cin>>n;
    int a[n],b[n],c[n];
    set<int> s;
    set<int> s1; 
    
    for(int i=0; i<n; i++)
     {
      cin>>a[i];
      s.insert(a[i]);
     } 

    for(int i=0; i<n; i++)
     cin>>b[i];

    for(int i=0; i<n; i++)
     cin>>c[i];

    for(int i=0; i<n; i++)
     if(s.find(b[i]) != s.end())
         s1.insert(b[i]);

    cout<<"Intersection of 3 Arrays is->";
    for(int i=0; i<n; i++)
     if(s1.find(c[i]) != s1.end())
      cout<<c[i]<<" ";

    return 0;            
}