#include<iostream>
using namespace std;

int findPower(int num , int power)
{
    if(power == 0)
     return 1;
    if(power == 1)
     return num;

    int ans = findPower(num, power/2);

    if(power%2 == 0)
     return ans * ans;
    else
     return num * ans * ans;   
}

int main()
{
    int num = 2;
    int power = 10;

    cout<<"Answer is: "<<findPower(num,power);

   return 0; 
}