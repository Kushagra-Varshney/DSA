//leetcode 49
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams1(vector<string>& strs) 
{
        map<string, vector<string>> mp;

        for(auto str: strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
}

 std::array<int,256>hashF(string s)
    {
        std::array<int,256> hash = {0};
        for(int i=0; i<s.size(); i++)
         hash[s[i]]++;

        return hash;
    }

vector<vector<string>> groupAnagrams2(vector<string>& strs) 
{
    map<std::array<int,256>,vector<string>>mp;

        for(auto str: strs)
        {
            mp[hashF(str)].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
}



int main()
{
  

 return 0;
}