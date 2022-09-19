//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid)
{
	int cowCount = 1;
	int lastPos = stalls[0];
	for(int i=0; i<stalls.size(); i++)
	{
		if(stalls[i]-lastPos >= mid)
		{
			cowCount++;
			if(cowCount == k)
				return true;
			lastPos = stalls[i];
		}
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
	int s = 0;
	int maxi;
	for(int i=0; i<stalls.size(); i++)
	{
		maxi = max(maxi , stalls[i]);
	}
	int e = maxi;
	int ans = -1;
	int mid = s + (e-s)/2;
	
	while(s<=e)
	{
		if(isPossible(stalls,k,mid))
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}

int main()
{
    vector<int> stalls;
    stalls.push_back(0);
    stalls.push_back(3);
    stalls.push_back(4);
    stalls.push_back(7);
    stalls.push_back(10);
    stalls.push_back(9);
    cout<<"Possible Solution:"<<aggressiveCows(stalls,4);

  return 0;

}
