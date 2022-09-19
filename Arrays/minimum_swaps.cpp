//Minimum swaps required to club all elements less than or equals
//to k together
#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cout<<"Enter Size and K->";
    cin>>n>>k;

    int a[n],count = 0,bad = 0,ans;

    for(int i=0; i<n; i++)
     { 
       cin>>a[i];
        if(a[i]<=k)
         count ++;
     }

    for(int i=0; i<count ; i++)
     if(a[i]>k)
      bad++;     

    ans = bad;

    for(int i=0, j=count; j<n; j++,i++)
     {
         if(a[i]>k)
          bad--;

         if(a[j]>k)
          bad++;

        ans = min(ans,bad);   
     } 

     cout<<"Minimun Swaps ->"<<ans;
 
  return 0;

}