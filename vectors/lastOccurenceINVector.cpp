// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> v(10);
//     for(int i=0;i<v.size();i++){
//         cin>>v[i];
//     }
//     int x;
//     cin>>x;
//     int occurence;
//     for(int i=0;i<v.size();i++){
//         if(v[i]==x) occurence=i;
//     }
//     cout<<occurence;
// }


#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(10);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    int occurence;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            occurence=i;
            break;
        }
    }
    cout<<occurence;
}