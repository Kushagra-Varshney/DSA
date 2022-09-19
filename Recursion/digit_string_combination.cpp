//Return diff combinations in a string of digits
#include<iostream>
#include<vector>
using namespace std;

void findCombinations(string digits, vector<string>& result, string output, int index)
{
   if(index == digits.size())
    {
        result.push_back(output);
        return;
    } 

   char ch = digits[index]; 
   output.push_back(ch); 
   //exclude space with character
    findCombinations(digits,result,output,index+1);
   //include space with character
    output.push_back(' ');
    if(digits[index+1] != '\0')
    findCombinations(digits,result,output,index+1);
}

int main()
{
    string digits = "123";
    vector<string> result;
    string output;
    int index = 0;

    findCombinations(digits,result,output,index);

    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }

   return 0; 
}