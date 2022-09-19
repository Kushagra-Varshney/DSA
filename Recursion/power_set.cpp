//Return Power Set of given string
#include<iostream>
#include<vector>
using namespace std;

void powerSet(string s, vector<string>& result, int index, string output)
{
    if(index >= s.size())
     {
        result.push_back(output);
        return;
     }

   //exclusion
   powerSet(s,result,index+1,output);
   //inclusion 
   output.push_back(s[index]);
   powerSet(s,result,index+1,output); 

}

int main()
{
    string s = "abc";
    vector<string> result;
    string output;
    int index = 0;

    powerSet(s,result,index,output);

    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }

   return 0;
}