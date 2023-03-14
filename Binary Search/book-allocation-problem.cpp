#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol )
    {
        int pageSum = 0; //keeps track of current sum of no of pages
        int studentCount = 1; // no of students who have been allocated books
        
        for(int i = 0; i<N; i++) // iterate for all books
        {
            if(A[i] > sol)
             return false;
             
            if(pageSum + A[i] > sol)
            {
                studentCount++;
                pageSum = A[i];
                
                if(studentCount > M)
                 return false;
            }
            else
             pageSum += A[i];
        }
        
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int s = 0;
        int e = accumulate(A, A+N, 0);
        int ans = -1;
        
        if (M > N)
         return -1;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(isPossibleSolution(A, N, M, mid))
             {
                 ans = mid;
                 e = mid -1;
             }
            else
             s = mid +1;
        }
        
        return ans;
    }

int main()
{
  

 return 0;
}