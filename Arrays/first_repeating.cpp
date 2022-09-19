//Find First Repeating element in array
#include<iostream>
#include<set>
using namespace std;

int main()
{
   int n;
   cout<<"Enter Size->";
   cin>>n;

   int a[n], min = -1;
   set<int> s;

   for(int i=0; i<n; i++)
     cin>>a[i];

   for(int i=n-1; i>0; i--)
    {
       if(s.find(a[i])!= s.end())
          min = i;
       else 
          s.insert(a[i]);
    }

    if(min != -1)
     cout<<"First Repeating Element is->"<<a[min];
    else 
     cout<<"No Repeating Element"; 

    return 0;   
}