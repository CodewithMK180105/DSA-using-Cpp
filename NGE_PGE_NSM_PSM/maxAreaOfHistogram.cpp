#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int histogram(vector<int>& arr){
    int n=arr.size();
    stack<int> st;
    int ans=-1;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            int nsi=i;
            int height=arr[st.top()];
            st.pop();
            int psi=!st.empty()?st.top():-1;
            ans=max(ans,(nsi-psi-1)*height);
        }
        st.push(i);
    }

    // for the remaining elements in the stack which dont have the nse
    while(!st.empty()){
        int nsi=n;
        int height=arr[st.top()];
        st.pop();
        int psi=!st.empty()?st.top():-1;
        ans=max(ans,(nsi-psi-1)*height);
    }

    return ans;
}
int main(){
    vector<int> v={2,1,5,6,2,3};
    int ans=histogram(v);
    cout<<ans;
    return 0;
}