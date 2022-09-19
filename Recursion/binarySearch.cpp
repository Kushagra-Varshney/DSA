//Implement Binary Search using Recursion
#include<iostream>
using namespace std;

bool binarySearch(int arr[], int key, int s, int e)
{
    if(s>e)
     return false;

    int mid = s + (e-s)/2;

    if(arr[mid] == key)
     return true;

    if(arr[mid]<key)
     binarySearch(arr,key,mid+1,e);
    else 
     binarySearch(arr,key,s,mid-1); 

}


int main()
{
    int arr[] = {2,3,4,5,6,7,8,9};
    int size = 8;
    int key = 70;
    int s = 0, e = size;
    

    cout<<binarySearch(arr,key,s,e); 
    
   return 0; 
}
