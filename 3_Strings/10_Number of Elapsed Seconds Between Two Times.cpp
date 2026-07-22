#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSeconds(string startTime){

        int hr = stoi(startTime.substr(0,2));
        int min = stoi(startTime.substr(3,2));
        int seconds = stoi(startTime.substr(6,2));

        return (hr*3600 + min*60 + seconds); //This is the case, where i was unable to think.
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        
        return (getSeconds(endTime) - getSeconds(startTime));
    }
};