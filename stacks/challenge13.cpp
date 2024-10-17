// Next Greater Element
// Given array:- 4,3,9,1,6,8,2
// Output array:- 9,9,-1,6,8,-1,-1

#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

int histogram(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    st.push(0);
    int ans=INT_MIN;
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int ele=arr[st.top()];
            int nsi=i;
            st.pop();
            int psi= st.empty()? -1: st.top();
            ans=max(ans,(nsi-psi-1)*ele);
        }
        st.push(i);
    }
    while(not st.empty()){ // If element is still present in the stack. It may happen when there is no nse
        int ele=arr[st.top()];
        int nsi=n;
        int psi= st.empty()? -1: st.top();
        ans=max(ans,(nsi-psi-1)*ele);
        st.pop();
    }
    return ans;
}

int main(){
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(6);
    input.push_back(2);
    input.push_back(3);
    input.push_back(0);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(6);
    input.push_back(2);
    input.push_back(3);

    int res=histogram(input);
    
    cout<<res;

    return 0;
}

// Note:- In the same way we can find the Next Smaller Element Array just by doing
//      arr[st.top()]>arr[i]

// Note:- Also we can find the previous smaller and previous greater element
// Just by reversing the input array pass the reversed array perform the operations on it find the output array and reverse the output array