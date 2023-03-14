#include<bits/stdc++.h>
using namespace std;
 vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        
        int carry = 0;
        
        for(int i =2; i<=N; i++)
        {
            for(int j = 0; j < ans.size(); j++)
             {
                 int x = ans[j] * i + carry; //multiply the last digit of ans with i
                 ans[j] = x%10; //multiply and store the digit
                 carry = x/10; // calculate the carry
             }
            //If carry remaining and multi digit 
            while(carry)
            {
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
int main()
{
    

 return 0;
}