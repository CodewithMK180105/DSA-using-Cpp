// Fist -ve number in every window of the size of k.
// Note that the test cases are generated such that the each consists of atleast one -ve int.


// Brute Force Solution 
// O(n*k)

// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int arr[]={2,-3,4,4,-7,-1,4,-2,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=3;
//     vector<int> v;

//     for(int i=0;i<n-k+1;i++){
//         for(int j=i;j<i+k;j++){
//             if(arr[j]<0){
//                 v.push_back(arr[j]);
//                 break;
//             }
//         }
//     }

//     for(int i=0;i<n-k+1;i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={2,-3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> v;

    int p=-1; // By default 1 if, no -ve int present in the window
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            p=i;
            break;
        }
    }

    v.push_back(arr[p]);

    int i=1,j=k;
    while(j<n){
        if(p>=i) v.push_back(arr[p]);
        else{
            for(p=i;p<j+1;p++){
                if(arr[p]<0){
                    break;
                }
            }
            v.push_back(arr[p]);
        }
        i++;
        j++;
    }

    for(int i=0;i<n-k+1;i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}