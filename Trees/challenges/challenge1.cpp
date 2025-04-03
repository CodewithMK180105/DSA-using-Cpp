// Print Elements of nth level.

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

void printNLevelNodes(TreeNode* root, int level, int maxLevel){
    if(!root) return;
    if(level==maxLevel){
        cout<<root->val<<" ";
        return;
    }
    printNLevelNodes(root->left, level+1, maxLevel);
    printNLevelNodes(root->right, level+1, maxLevel);
}

int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(7);
    TreeNode* c=new TreeNode(9);
    TreeNode* d=new TreeNode(2);
    TreeNode* e=new TreeNode(6);
    TreeNode* f=new TreeNode(9);
    TreeNode* g=new TreeNode(5);
    TreeNode* h=new TreeNode(11);
    TreeNode* i=new TreeNode(5);

//          1
//         / \
//        /   \
//       7     9
//      / \     \
//     2   6     9
//        / \    /
//       /   \  5
//      /     \ 
//     5       11

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    e->left=g;
    e->right=h;
    f->left=i;

    printNLevelNodes(a,0,0);
    cout<<endl;
    printNLevelNodes(a,0,1);
    cout<<endl;
    printNLevelNodes(a,0,2);
    cout<<endl;
    printNLevelNodes(a,0,3);
    return 0;
}