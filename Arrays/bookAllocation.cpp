//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
#include<iostream>
#include<vector>
using namespace std;

bool isPossibleSolution(vector<int> arr, int n, int m, int mid)
{
    int students = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++)
    {
        if (pageSum + arr[i] <= mid)
         {
             pageSum += arr[i];
         }
        else
         {
             students ++;
             if(students > m || arr[i]>mid)
              return false; 

             pageSum = arr[i]; 
         } 
    }
  return true;

}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++)
     sum += arr[i];

    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e)
     { 
        if(isPossibleSolution(arr,n,m,mid))
         {
           ans = mid;
           e = mid - 1;
         }  
        else 
          s = mid + 1;

        mid = s + (e-s)/2;    
     } 
   return ans;
}

int main()
{
     vector<int> arr;
     arr.push_back(25);
     arr.push_back(46);
     arr.push_back(28);
     arr.push_back(49);
     arr.push_back(24);

     cout<<"Solution is:"<<allocateBooks(arr,5,4);

    return 0;

}