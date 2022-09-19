//https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557?leftPanelTab=0
#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid)
{
	int painter = 1;
	int timeCount = 0;
	
	for(int i =0; i<boards.size(); i++)
	{
		if(timeCount + boards[i] <= mid)
		{
			timeCount += boards[i];
		}
		else 
		{
			painter++;
			if(painter > k || boards[i]>mid)
				return false;
			timeCount = boards[i];
		}
	}
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
	int sum = 0;
	
	for(int i=0; i<boards.size(); i++)
		sum += boards[i];
	int e = sum;
	int ans = -1;
	int mid = s + (e-s)/2;
	
	while(s<=e)
	{
		if(isPossible(boards,k,mid))
		{
			ans = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		} 
       mid = s + (e-s)/2; 
	}
	return ans;
}
int main()
{
   vector<int> boards;
   boards.push_back(1);
   boards.push_back(2);
   boards.push_back(3);
   boards.push_back(4);

   cout<<"Possible Solution:"<<findLargestMinDistance(boards,2);

  return 0;
}