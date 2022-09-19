//Find First non repeating element in array
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
   int n;
   cout<<"Enter Size->";
   cin>>n;

   int a[n]; 
   unordered_map<int,int> m;

   for(int i=0; i<n; i++ )
    {
      cin>>a[i];
    }
    
    for(int i=0; i<n; i++)
     {
       m[a[i]]++;
     }
     
    for(int i=0; i<n; i++)
     {
       if(m[a[i]]==1)
        {
          cout<<"First Non Repeating Element->"<<a[i];
          break;
        }
     }

    return 0;  
}
