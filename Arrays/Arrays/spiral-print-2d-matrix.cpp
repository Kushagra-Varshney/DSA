#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
     int colStart = 0, rowStart = 0, colEnd = matrix[0].size()-1, rowEnd = matrix.size()-1;

     while(colStart <= colEnd && rowStart <= rowEnd)
     {
        for (int i = colStart; i <= colEnd; i++)
        {
            cout<<matrix[rowStart][i]<<" ";
        }
        rowStart ++ ;

        for (int i = rowStart; i <= rowEnd; i++)
        {
            cout<<matrix[i][colEnd]<<" ";
        }
        colEnd -- ;

        for(int i = colEnd; i >= colStart; i--)
        {
            cout<<matrix[rowEnd][i]<<" ";
        }
        rowEnd -- ;

        for(int i = rowEnd; i >= rowStart; i--)
        {
            cout<<matrix[i][colStart]<<" ";
        }
        colStart ++ ;
        
     }   
}

int main()
{
   vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    spiralOrder(matrix);
 return 0;
}