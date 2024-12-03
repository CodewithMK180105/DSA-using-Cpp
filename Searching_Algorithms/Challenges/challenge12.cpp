// A new racing track for kids in being built in New York with 'n' starting spots are located along a straight line at positions x1,x2,...(x[i]<1000000000). For each 'i' x[i+1]>x[i]. At any time only 'm' children are allowed to enter the race. Since the race track for kids, they may run into each other while running. To prevent this, we want to choose the starting spots such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// The first line of the input will contain the value of n, the number of the starting spots.
// The second line of the input will contain the 'n' numbers, denoting the location of each spot.
// The third will contain the value of 'm', number of children.

// Input: 5
//        1 2 4 8 9
//        3

// Output: 3

#include<iostream>
#include<vector>
using namespace std;
bool canPlaceStudents(vector<int>& v,int s,int mid){
    int n=v.size();
    int possibleStudents=1;
    int lastPos=v[0];
    for(int i=1;i<n;i++){
        if(v[i]-lastPos>=mid){
            possibleStudents++;
            lastPos=v[i];
            if(possibleStudents==s) return true;
        }
    }
    return false;
}
int race(vector<int>& v,int s){
    int n=v.size(),ans=-1;
    int low=1,high=v[n-1]-v[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canPlaceStudents(v,s,mid)){
            ans=mid;
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int st; cin>>st;
    cout<<race(v,st);
    return 0;
}