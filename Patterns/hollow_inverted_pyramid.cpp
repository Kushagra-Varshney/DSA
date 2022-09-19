#include<iostream>
using namespace std;

int main()
{
   int n;
   cout<<"Enter Number of Rows->";
   cin>>n;

   for(int i=1; i<=n; i++)
    {
        if(i==1)
         { for(int x=0; x<n; x++)
           cout<<"*";
           continue;
         }  
          cout<<endl;
        if(i==n)
         {
             cout<<"*"; 
             break; 
         }  
        cout<<"*";
        for(int j=0; j<(n-i-1); j++)
         cout<<" ";
        cout<<"*";

    } 
}