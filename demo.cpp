#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={10, 4, -8, 7};
    int n=nums.size();
    vector<int> prefix_sum(n,0);
    vector<int> suffix_sum(n,0);

    prefix_sum[0]=nums[0];
    suffix_sum[n-1]=nums[n-1];

    for(int i=1;i<n;i++){
        prefix_sum[i]=nums[i]+prefix_sum[i-1];
        suffix_sum[n-i-1]=nums[n-i-1]+suffix_sum[n-i];
    }
    
    for(int i=0;i<n;i++){
        cout<<prefix_sum[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<suffix_sum[i]<<" ";
    }
    
    return 0;
}