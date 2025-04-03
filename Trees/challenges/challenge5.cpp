// Left View Of a Binary Tree.

// Given a Binary Tree, print the left view of it.
// The left view of the binary tree refers to the set of nodes that are visible when the tree is viewed from the left side.

#include<iostream>
#include<queue>
#include<vector>
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
vector<int> leftView(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();

            if(i==0){
                ans.push_back(temp->val);
            }

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}
int main(){
    // Creating another binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->right->left->left = new TreeNode(70);

    // Printing the left view
    cout << "Left View of the Tree: ";
    vector<int> ans= leftView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}


//         10
//        /  \
//       20   30
//      /    /  \
//     40   50   60
//         /
//        70
