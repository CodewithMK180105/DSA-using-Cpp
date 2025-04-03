// Write a Program to find the inorder-predecessor and inorder-successor of the given node in a tree.

#include<iostream>
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

void inOrder(TreeNode* root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int inorderPredecessor(TreeNode* root){
    if(!root->left){
        cout<<"No inorder predecessor exists"<<endl;
        return 0;
    }
    TreeNode* pred= root->left;
    while(pred->right){
        pred=pred->right;
    }
    return pred->val;
}

int inorderSuccessor(TreeNode* root){
    if(!root->right){
        cout<<"No inorder successor exists"<<endl;
        return 0;
    }
    TreeNode* pred= root->right;
    while(pred->left){
        pred=pred->left;
    }
    return pred->val;
}

int main(){
    TreeNode* a=new TreeNode(2);
    TreeNode* b=new TreeNode(3);
    TreeNode* c=new TreeNode(4);
    TreeNode* d=new TreeNode(5);
    TreeNode* e=new TreeNode(8);
    TreeNode* f=new TreeNode(10);
    TreeNode* g=new TreeNode(12);
    TreeNode* h=new TreeNode(13);
    TreeNode* i=new TreeNode(15);
    TreeNode* j=new TreeNode(20);
    TreeNode* k=new TreeNode(25);

    f->left=d;
    f->right=j;
    d->left=a;
    d->right=e;
    a->right=c;
    c->left=b;
    j->left=i;
    j->right=k;
    i->left=g;
    g->right=h;
    j->right=k;

    inOrder(f);
    cout<<endl;

    cout<<inorderPredecessor(f)<<endl;
    cout<<inorderSuccessor(j)<<endl;

//      10
//     /  \
//   5     20
//  / \    /  \
// 2   8  15   25
//  \     /
//   4   12
//  /      \
// 3        13



    return 0;
}