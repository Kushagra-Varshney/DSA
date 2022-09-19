//Check if an Array is Sorted Using recursion 
#include<iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if(size == 1 || size == 0)
     return true;

    if(arr[0]>arr[1])
     return false;
    else 
     isSorted(arr+1,size-1);  
}

int main()
{
    int arr[] = {2,4,6,7,8,9};
    int size = 6;

    bool ans = isSorted(arr, size);
    if(ans == 1)
     cout<<"Sorted";
    else
     cout<<"Not Sorted";

   return 0;   
}
