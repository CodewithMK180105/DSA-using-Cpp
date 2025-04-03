// Construct a Binary Tree using an Array.

#include<iostream>
#include<queue>
#include<climits>
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
void bfsLevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp=q.front();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        cout<<temp->val<<" ";
        q.pop();
    }
}
void bfsLevelOrderRev(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp=q.front();
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        cout<<temp->val<<" ";
        q.pop();
    }
}
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
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr, n);
    bfsLevelOrder(root);
    cout<<endl;
    bfsLevelOrderRev(root);
    return 0;
}