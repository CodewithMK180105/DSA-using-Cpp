#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> jnge(vector<int>& v){
    stack<int> st;
    int n=v.size();
    vector<int> nge(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]<v[i]){
            nge[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}
vector<int> jpge(vector<int> &v){
    reverse(v.begin(),v.end());
    vector<int> pge=jnge(v);
    reverse(pge.begin(),pge.end());
    return pge;
}
int main()
{
    vector<int> v={4,6,3,1,0,9,5,6,7,3};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> pge=jpge(v);
    for(int i=0;i<v.size();i++){
        cout<<pge[i]<<" ";
    }
    return 0;
}