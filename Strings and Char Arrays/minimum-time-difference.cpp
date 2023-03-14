#include<bits/stdc++.h>
using namespace std;

 int findMinDifference(vector<string>& timePoints) {
        
        //covert all times into minutes
        vector<int> minutes;

        for(int i=0; i<timePoints.size(); i++)
        {
            string curr = timePoints[i];

            int hours = stoi(curr.substr(0,2));
            int currMinutes = stoi(curr.substr(3,2));
            int total = hours*60 + currMinutes;
             minutes.push_back(total);
        }

        //sort the minutes array so minimum diff is the diff b/w adjacent times
        sort(minutes.begin(), minutes.end());
        int diff = INT_MAX;

        for(int i=0; i<minutes.size()-1; i++)
        {
            diff = min(diff, minutes[i+1]-minutes[i]);
        }

        int lastDiff = (minutes[0]+1440) - minutes[minutes.size()-1];

        diff = min(diff, lastDiff);

        return diff;
    }

int main()
{
  

 return 0;
}