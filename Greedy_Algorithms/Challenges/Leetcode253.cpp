// 253. Meeting Rooms II

// Given an array of meeting time intervals where intervals[i]=[start[i], end[i]], return the minimum number of the conference rooms required.
// Input: [[0,30], [5,10], [15,20]]
// Output: 2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> timing={{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
    vector<int> start;
    vector<int> end;
    for(int i=0;i<timing.size();i++){
        start.push_back(timing[i][0]);
        end.push_back(timing[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int maxRooms=0;
    int rooms=0;
    int i=0,j=0;
    while(i<start.size()){
        if(start[i]<end[j]){
            rooms++;
            i++;
            maxRooms=max(rooms, maxRooms);
        } else{
            rooms--;
            j++;
        }
    }
    cout<<maxRooms;
    return 0;
}