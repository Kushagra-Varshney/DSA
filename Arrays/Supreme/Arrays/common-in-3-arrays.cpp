//https://practice.geeksforgeeks.org/problems/common-elements1132/1
#include<bits/stdc++.h>
using namespace std;

void findCommon(vector<int> A, vector<int> B, vector<int> C)
{
    int i, j, k;
    i = j = k = 0;

    while(i < A.size() && j < B.size() && k < C.size())
    {
        if(A[i] == B[j] && B[j] == C[k])
         {
            cout<<A[i]<<" ";
            i++; j++; k++;
         }

        if(A[i] < B[j])
         i++;
        else if(B[j] < C[k])
         j++;
        else 
         k++; 
    }
}

int main()
{
   vector<int> A = {1, 5, 10, 20, 40, 80};
   vector<int> B = {6, 7, 20, 80, 100};
   vector<int> C = {3, 4, 15, 20, 30, 70, 80, 120};

   findCommon(A,B,C);

 return 0;
}