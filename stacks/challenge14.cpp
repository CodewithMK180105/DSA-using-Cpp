// Given a Series of N daily price quotes of a stock, we need to calculate the span of
// the stock's price for all N days. The span of the stock's price in one day is the 
// maximum number of consecutive days (starting from that day and going backward)
// for which the stock price was less than or equal to the price of that day

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pge(vector<int> &arr){
    int n=arr.size();
    reverse(arr.begin(),arr.end());
    stack<int> st;
    vector<int> output(n,-1);
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            output[st.top()]=n-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
}

int main(){
    vector<int> input;
    input.push_back(100);
    input.push_back(80);
    input.push_back(60);
    input.push_back(70);
    input.push_back(60);
    input.push_back(75);
    input.push_back(80);

    vector<int> res=pge(input);
    
    for(int i=0;i<res.size();i++) cout<<i-res[i]<<" ";

    return 0;
}
