#include<iostream>
#include<queue>
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
void bfsLevelOrderReverse(TreeNode* root){
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

    bfsLevelOrder(a);
    cout<<endl;
    bfsLevelOrderReverse(a);
    
    return 0;
}