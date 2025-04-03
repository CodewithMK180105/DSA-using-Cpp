#include<iostream>
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

int NodesSum(TreeNode* root){
    if(!root) return 0;
    return root->val+NodesSum(root->left)+NodesSum(root->right);
}

int NodesProduct(TreeNode* root){
    if(!root) return 1;
    return root->val*NodesProduct(root->left)*NodesProduct(root->right);
}

int size(TreeNode* root){
    if(!root) return 0;
    return 1+size(root->left)+size(root->right);
}

int maxVal(TreeNode* root){
    if(!root) return INT_MIN;
    return max(root->val,max(maxVal(root->left),maxVal(root->right)));
}

int minVal(TreeNode* root){
    if(!root) return INT_MAX;
    return min(root->val, min(minVal(root->left),minVal(root->right)));
}

int height(TreeNode* root){
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}

int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);
    // TreeNode* h=new TreeNode(0);

//          a
//         / \
//        /   \
//       b     c
//      / \   / \
//     d   e f   g 

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    // g->right=h;
    
    cout<<NodesSum(a)<<endl;
    cout<<NodesProduct(a)<<endl;
    cout<<size(a)<<endl;
    cout<<maxVal(a)<<endl;
    cout<<minVal(a)<<endl;
    cout<<height(a)<<endl;
    
    return 0;
}