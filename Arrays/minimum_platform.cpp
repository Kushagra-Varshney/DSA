/*Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.*/
#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arr[],int dep[], int n)
 {
    int platform =0,result=0;
    int i=0,j=0;

    sort(arr, arr+n);
    sort(dep, dep+n);

    while(i<n && j<n)
     {
         if(arr[i]<=dep[j])
          {
              platform ++;
              i++;
          }
         else 
          {
              platform --;
              j++; 
          }

        result = max(platform,result);   
     }

    return result; 

 }


int main()
{
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arr)/sizeof(int);
  cout<<"Platform Required->"<<minPlatform(arr,dep,6); 
  
  return 0;

}
