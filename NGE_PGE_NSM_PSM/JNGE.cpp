#include <iostream>
#include <stack>
#include <vector>
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
int main()
{
    vector<int> v={4,6,3,1,0,9,5,6,7,3};
    vector<int> nge=jnge(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<nge[i]<<" ";
    }

    return 0;
}