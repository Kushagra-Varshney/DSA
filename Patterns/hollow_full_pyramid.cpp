#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Rows->";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n-i-1; j++)
         cout<<" ";

        if(i==0)
        {
            cout<<"*"<<endl;
            continue;
        }
        if(i==n-1)
        {
            for(int x=0; x<n; x++)
             cout<<"* ";
             continue;
        } 

        cout<<"*";
        for(int k=0; k<2*i-1; k++)
         cout<<" ";
        cout<<"*"<<endl;

    }      
  return 0;

}