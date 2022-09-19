//Return the number of ways of making the given amount using given array of different coins
#include<iostream>
using namespace std;

int findWays(int coins[], int amount, int index, int size)
{
    if(amount == 0)
     {
        return 1; 
     }
    if(amount <0)
     {
         return 0;
     } 
     int ways = 0;
     for(int i = index; i<size; i++)
      {
        ways+=findWays(coins,amount-coins[i],i,size);
      }

   return ways;   
}

int main()
{
    int coins[] = {1,2};
    int size = 2;
    int amount = 4;
    int index = 0;
       
    cout<<"No of Ways: "<<findWays(coins,amount,index,size);

  return 0;
}