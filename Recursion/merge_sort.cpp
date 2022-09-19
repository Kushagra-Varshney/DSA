//Implement Merge sort
#include<iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e-s)/2;

    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *left = new int[leftLength];
    int *right = new int[rightLength];

    int originalIndex = s;

    for(int i = 0; i<leftLength; i++)
     left[i] = arr[originalIndex++];

    originalIndex = mid+1; 

    for(int i = 0; i<rightLength; i++)
     right[i] = arr[originalIndex++];

    // Now we have 2 sorted arrays and now we need to merge

    int leftIndex = 0;
    int rightIndex = 0;
    originalIndex = s;

    while(leftIndex < leftLength && rightIndex < rightLength)
    {
        if(left[leftIndex] <= right[rightIndex])
          arr[originalIndex++] = left[leftIndex++];
        else 
          arr[originalIndex++] = right[rightIndex++];  
    }
    
    while(leftIndex < leftLength)
     arr[originalIndex++] = left[leftIndex++];

    while(rightIndex < rightLength)
     arr[originalIndex++] = right[rightIndex++];

}


void mergeSort(int arr[], int s, int e)
{
    if(s>=e)
     return;

    int mid = s + (e-s)/2;

    mergeSort(arr,s,mid);

    mergeSort(arr,mid+1,e);

    merge(arr,s,e); 
}


int main()
{
    int arr[] = {35,34,6,4,2,5};
    int size = 6;

    mergeSort(arr,0,6-1);

    cout<<"Sorted Array: ";
    for(int i =0 ; i<6; i++)
     cout<<arr[i]<<" ";

   return 0;  
}