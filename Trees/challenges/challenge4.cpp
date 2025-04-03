// Print all the Boundary Nodes of the Tree.

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
void printLeftBoundary(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right) return;
    cout<<root->val<<" ";
    printLeftBoundary(root->left);
    if(!root->left) printLeftBoundary(root->right);
}
void printLeaf(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right) cout<<root->val<<" ";
    printLeaf(root->left);
    printLeaf(root->right);
}
void printRightBoundary(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right) return;
    printRightBoundary(root->right);
    if(!root->right) printRightBoundary(root->left);
    cout<<root->val<<" ";
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,29,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr, n);
    bfsLevelOrder(root);
    cout<<endl;
    printLeftBoundary(root);
    printLeaf(root);
    printRightBoundary(root->right);
    return 0;
}