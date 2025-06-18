// Problem 1: Minimum Cost to Cut a Board into Squares
// A board of length M and width N is given. The task is to break this board into M × N squares such that the cost of breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.

// Input:
// M = 6, N = 4
// X[] = {2, 1, 3, 1, 4}
// Y[] = {4, 1, 2}

// Output:
// 42

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minCost(int &m, int &n, vector<int> &x, vector<int> &y){
    int hr=1, vr=1, cost=0;
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    int i=0,j=0;
    while(i<x.size() && j<y.size()){
        if(x[i]>y[j]){
            cost+=x[i]*hr;
            i++;
            vr++;
        } else {
            cost+=y[j]*vr;
            j++;
            hr++;
        }
    }
    while(i<x.size()){
        cost+=x[i]*hr;
        i++;
        vr++;
    }
    while(j<y.size()){
        cost+=y[j]*vr;
        j++;
        hr++;
    }

    return cost;
}
int main(){
    int m=4,n=6;
    vector<int> x={2,1,3,1,4};
    vector<int> y={4,1,2};

    cout<<minCost(m,n,x,y);
    return 0;
}