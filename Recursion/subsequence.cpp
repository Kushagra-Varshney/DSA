//https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16
#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans)
{
    //base case
    if(index >=str.length())
    {
        if(output.length()>0)
        ans.push_back(output);
        return;
    }
    
    //exclude
    solve(str,output,index+1,ans);
    //include
    char ch = str[index];
    output.push_back(ch);
    solve(str,output,index+1,ans);    
}

vector<string> subsequences(string str){

          int index = 0;
          vector<string> ans;
          string output = "";
    
    solve(str,output,index,ans);
  return ans;
}