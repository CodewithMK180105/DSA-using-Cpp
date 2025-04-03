// Level Order Traversal using the DFS.

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

int findHeight(TreeNode* root){
    if(!root) return 0;
    return 1+max(findHeight(root->left),findHeight(root->right));
}

void printNLevelNodes(TreeNode* root, int level, int maxLevel){
    if(!root) return;
    if(level==maxLevel){
        cout<<root->val<<" ";
        return;
    }
    printNLevelNodes(root->left, level+1, maxLevel);
    printNLevelNodes(root->right, level+1, maxLevel);
}
void printNLevelNodesRightToLeft(TreeNode* root, int level, int maxLevel){
    if(!root) return;
    if(level==maxLevel){
        cout<<root->val<<" ";
        return;
    }
    printNLevelNodesRightToLeft(root->right, level+1, maxLevel);
    printNLevelNodesRightToLeft(root->left, level+1, maxLevel);
}

int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);
    TreeNode* h=new TreeNode(8);
    TreeNode* i=new TreeNode(9);

//          1
//         / \
//        /   \
//       2     3
//      / \     \
//     4   5     6
//        / \    /
//       /   \  9
//      /     \ 
//     7       8

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    e->left=g;
    e->right=h;
    f->left=i;

    int height=findHeight(a);

    for(int i=0;i<height;i++){
        printNLevelNodes(a,0,i);
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        printNLevelNodesRightToLeft(a,0,i);
    }

    return 0;
}