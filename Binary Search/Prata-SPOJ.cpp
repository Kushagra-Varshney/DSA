#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(vector<int> ranks, int pratasOrdered, int maxTime)
{
    int pratasCooked = 0;

    for(int i = 0; i<ranks.size(); i++)
    {
        int currentTime = 0;
        int temp = 1, r = ranks[i];

        while(true)
        {
            if(currentTime + temp*r <= maxTime)
            {
                pratasCooked++;
                currentTime += temp*r;
                temp++;
            }
            else{
                break;
            }
        }

        if(pratasCooked >= pratasOrdered)
         return true;
    }

    return false;
}

int solve(vector<int> ranks, int pratasOrdered)
{
    int s = 0;
    int maxRank = *max_element(ranks.begin(), ranks.end());
    int e = maxRank*(pratasOrdered*(pratasOrdered+1)/2);
    int ans = -1;

    while(s <= e)
    {
        int mid = s + (e-s)/2;

        if(isPossibleSolution(ranks, pratasOrdered, mid))
        {
            ans = mid;
            e = mid -1;
        }
        else
         s = mid +1;
    }

    return ans;
}

int main()
{
  vector<int> ranks = {1, 2, 3, 4};

  cout<<"Min time Required is: "<<solve(ranks,10);

 return 0;
}