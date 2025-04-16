// Print the Top view of the Binary Tree.

// Construct a Binary Tree using an Array.

#include<iostream>
#include<queue>
#include<climits>
#include<unordered_map>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};

TreeNode* construct(int arr[], int n){
    if(n==0) {
        cout<<"Given array is empty";
        return NULL;
    }
    TreeNode* root=new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i=1,j=2;

    while(!q.empty() && i<n){
        TreeNode* temp=q.front();
        q.pop();

        TreeNode* l;
        TreeNode* r;

        if(arr[i]!=INT_MIN) l= new TreeNode(arr[i]);
        else l=NULL;
        if(j<n && arr[j]!=INT_MIN) r= new TreeNode(arr[j]);
        else r=NULL;

        temp->left=l;
        temp->right=r;

        if(l) q.push(l);
        if(r) q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}
void topView(TreeNode* root){
    unordered_map<int, int> mp; // (level, val)
    queue<pair<TreeNode*, int>> q; // (Node, level)

    pair<TreeNode*, int> p1;
    p1.first=root;
    p1.second=0;
    q.push(p1);

    mp[0]=root->val;

    while(!q.empty()){
        pair<TreeNode*, int> p2=q.front();
        q.pop();

        if(mp.find(p2.second)==mp.end()){
            mp[p2.second]=p2.first->val;
        }

        if(p2.first->left){
            pair<TreeNode*, int> p3;
            p3.first=p2.first->left;
            p3.second=p2.second-1;
            q.push(p3);
        }
        if(p2.first->right){
            pair<TreeNode*, int> p3;
            p3.first=p2.first->right;
            p3.second=p2.second+1;
            q.push(p3);
        }
        
    }
    
    int minLevel=INT_MAX;
    int maxLevel=INT_MIN;

    for(auto x: mp){
        minLevel=min(minLevel, x.first);
        maxLevel=max(maxLevel, x.first);
    }

    for(int i=minLevel; i<=maxLevel; i++){
        cout<<mp[i]<<" ";
    }
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr, n);
    topView(root);
    return 0;
}