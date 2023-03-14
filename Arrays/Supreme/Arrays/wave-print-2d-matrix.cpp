#include<bits/stdc++.h>
using namespace std;

int main()
{
   int arr[3][3] = {
                        {1,6,7},
                        {2,5,8},
                        {3,4,9}
                   };

   for(int startCol = 0; startCol < 3; startCol++)
   {
     if((startCol & 1) == 0)
     {
        for (int row = 0; row < 3; row++)
        {
            cout<<arr[row][startCol]<<" ";
        }  
     }
     else
     {
        for (int row = 2; row >= 0; row--)
        {
            cout<<arr[row][startCol]<<" ";
        }
        
     }
   }               

 return 0;
}