//Find all even binary sequences such that sum of left half and right half is same
#include<iostream>
using namespace std;

void findSequences(int leftSum, int rightSum, char* output, int i, int j)
{
    if(i > j)
     {
         if(leftSum == rightSum)
          cout<<output<<endl;
         return; 
     }

   //Case 1 - Put 0 and 0
   output[i] = '0';
   output[j] = '0';
   findSequences(leftSum, rightSum, output, i+1, j-1); 

   //Case 2 - Put 0 and 1
   output[i] = '0';
   output[j] = '1';
   findSequences(leftSum, rightSum+1, output, i+1, j-1);

   //Case 3 - Put 1 and 0
   output[i] = '1';
   output[j] = '0';
   findSequences(leftSum+1, rightSum, output, i+1, j-1);

   //Case 4 - Put 1 and 1
   output[i] = '1';
   output[j] = '1';
   findSequences(leftSum+1, rightSum+1, output, i+1, j-1);
     
}

int main()
{
   int n;
   cout<<"Enter the Value of n: ";
   cin>>n;
   char* output = new char[2*n];
   findSequences(0,0,output,0,(2*n - 1));
   delete[] output;
  return 0;
}