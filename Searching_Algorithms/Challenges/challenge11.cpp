// You have 'n'(n<=100000) boxes of chocolates. Each box contains a[i] (a[i]<=10000) chocolates. You need to distribute this  boxes among the 'm' students such that the maximum number of chocolates allocated to a student is minimum.
// a. One box will be allocated to exactly one student.
// b. All boxes should be allocated.
// c. Each student has to be allocated atleast one box.
// d. Allotment should be in a contiguous order, for instance, a student cannot be allocated box 1 and box 3, skipping the box 2.

// Calculate and return that minimum possible number.
// Assume that it is always possible to distribute the chocolates.

// The first line of the input will contain a value of n, the number of boxes.
// The second line of the input will contain the n numbers denoting the number of chocolates in each box.
// The third line will contain the m, number of students.

// Input: 4
//        12 34 67 90
//        2

// Output: 113

// Explaination:

// s1=12+34=46
// s2=67+90=157

// s1=12+34+67=113
// s2=90

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canDistChoco(vector<int>& v,int mid,int s){
    int n=v.size();
    int currSum=0;
    int stdReq=1;
    for(int i=0;i<n;i++){
        if(v[i]>mid){
            return false;
        }
        if(currSum+v[i]>mid){
            stdReq++;
            currSum=v[i];
            if(stdReq>s) return false;
        } else{
            currSum+=v[i];
        }
    }
    return true;
}
int distrubutionOfChocolates(vector<int>& v,int s){
    int n=v.size();

    // sort the vector
    sort(v.begin(),v.end());

    // set boundaries
    int low=v[0];
    int high=0;
    for(int i=0;i<n;i++){
        high+=v[i];
    }

    // chicking in the boundaries
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canDistChoco(v,mid,s)){
            ans=mid;
            high=mid-1;
        } else{
            low=mid+1;
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
    cout<<distrubutionOfChocolates(v,st);
    return 0;
}