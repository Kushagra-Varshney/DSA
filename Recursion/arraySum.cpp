//Print Sum of Array using Recursion
#include<iostream>
using namespace std;

int findSum(int arr[], int size)
{
    if(size == 0)
     return 0;

    int sum = arr[0] + findSum(arr+1, size-1);

    return sum; 
}

int main()
{
    int arr[] = {2,65,3,12,45,6};
    int size = 6;

    cout<<findSum(arr,size);

   return 0; 
}