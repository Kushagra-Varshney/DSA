//To Implement Quick Sort
#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
   int pivot = arr[s];
   int cnt = 0;

   for(int i = s+1; i<=e; i++)
    if(arr[i] <= pivot)
      cnt ++;

   int pivotIndex = s + cnt;

   swap(arr[s],arr[pivotIndex]);

   //Handle Left and Right Parts

   int i = s, j = e; 

   while(i < pivotIndex && j > pivotIndex)
    {
       //already smaller elements on left side
       while(arr[i] <= pivot)
        i++;

       //already greater elements on right side
       while(arr[j] >= pivot)
        j--;

       if(i < pivotIndex && j > pivotIndex)
        {
          swap(arr[i],arr[j]);
          i++; j--;
        }    
    }
  return pivotIndex;    
}

void quickSort(int arr[], int s, int e)
{
   if(s>=e)
    return;

   int pIndex = partition(arr,s,e);

   quickSort(arr,s,pIndex-1);

   quickSort(arr,pIndex+1,e); 
}


int main()
{
    int arr[] = {234,45,5633,23,5245,6};
    int size = 6;
    int s = 0; int e = size - 1;

    quickSort(arr,s,e);

    cout<<"Sorted Array: ";
    for(int i =0 ; i<size; i++)
     cout<<arr[i]<<" ";

  return 0;   
}