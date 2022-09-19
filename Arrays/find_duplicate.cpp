//Numbers input from 1 - N and only one number repeats 
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Size->";
    cin>>n;

    int a[n+1];
    int sum1=0,sum2;

    for(int i=0; i<n+1; i++)
     {
       cin>>a[i];
       sum1 += a[i];
     }  

    sum2 =  (n*(n+1))/2;

    cout<<"Duplicate Number is->"<<sum1-sum2;

  return 0; 
     
}
