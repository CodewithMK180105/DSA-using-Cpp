#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> jnse(vector<int>& v){
    stack<int> st;
    int n=v.size();
    vector<int> nse(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]>v[i]){
            nse[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    return nse;
}
vector<int> jpse(vector<int> &v){
    reverse(v.begin(),v.end());
    vector<int> pse=jnse(v);
    reverse(pse.begin(),pse.end());
    return pse;
}
int main()
{
    vector<int> v={4,6,3,1,0,9,5,6,7,3};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> pse=jpse(v);
    for(int i=0;i<v.size();i++){
        cout<<pse[i]<<" ";
    }
    return 0;
}