#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> jpge(vector<int> &v){
    int n=v.size();
    reverse(v.begin(),v.end());
    vector<int> output(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[i]>v[st.top()]){
            output[st.top()]=n-i-1; // because after reverse the index changes
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(v.begin(),v.end());
    return output;
}
int main(){
    vector<int> price={100,80,60,70,60,75,85};
    for(int i=0;i<price.size();i++){
        cout<<price[i]<<" ";
    }
    cout<<endl;
    vector<int> spanData=jpge(price);
    for(int i=0;i<price.size();i++){
        cout<<i-spanData[i]<<" ";
    }
    return 0;
}