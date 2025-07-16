#include<iostream>
#include<unordered_set>
using namespace std;
void permutations(string & str, int i){
    if(i==str.size()-1){
        cout<<str<<" ";
        return;
    }

    unordered_set<int> st;
    for(int idx=i;idx<str.size();idx++){
        if(st.count(str[idx])) continue;  // pruning step
        st.insert(str[idx]);

        swap(str[idx], str[i]);
        permutations(str, i+1);
        swap(str[idx], str[i]);  // step of backtracking
    }
}
int main(){
    string str="aba";
    permutations(str, 0);
    return 0;
}