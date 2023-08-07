#include<bits/stdc++.h>
using namespace std;

int minTimeDiff(vector<string>timePoints){
    int n=timePoints.size();
    vector<int>minutes;
    for(int i=0;i<n;i++){
        string curr=timePoints[i];
        int hours = stoi(curr.substr(0,2));
        if(hours == 0)hours=24;
        int mintue = stoi(curr.substr(3,2));
        int totalMinutes = hours*60 + mintue;
        minutes.push_back(totalMinutes);
    }
    sort(minutes.begin() , minutes.end());
    int mindiff=INT32_MAX;
    for(int i=1 ; i<minutes.size() ; i++){
        if(minutes[i]-minutes[i-1] < mindiff)mindiff=minutes[i]-minutes[i-1];
    }

    int lastdiff1 = minutes[0]+1440 - minutes[minutes.size()-1];  
    int lastdiff2 = minutes[minutes.size()-1] - minutes[0];  
    int lastdiff = min(lastdiff1,lastdiff2);
    return min(mindiff,lastdiff);
}
int main(){
    vector<string>timePoints(6);
    for(int i=0;i<6;i++)cin >> timePoints[i];
    cout << minTimeDiff(timePoints);
}