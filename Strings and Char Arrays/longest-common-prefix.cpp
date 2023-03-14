#include<bits/stdc++.h>
using namespace std;

 string longestCommonPrefix(vector<string>& strs) 
 {
       string ans="";
        for(int i=0; i<strs[0].size(); i++)
        {
            char currChar = strs[0][i];
            bool isPrefix = true;
             for(int j=1; j<strs.size(); j++)
             {
                 if(strs[j][i] != currChar)
                  {
                      isPrefix = false;
                  }
             }

             if(isPrefix)
              ans.push_back(currChar);
             else
              break;
        }
      return ans;
}

int main()
{
  

 return 0;
}