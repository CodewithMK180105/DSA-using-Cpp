#include<iostream>
#include<vector>
#include<algorithm>
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

void preOrder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode* root, vector<int> &v){
    if(!root) return;
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
}

// Using the BFS to convert the BST to MinHeap
void bfs(TreeNode* a, vector<int> &v){
    queue<TreeNode*> q;
    q.push(a);
    int i=0;
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        temp->val=v[i++];
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

// Using the preOrder method for the conversion of the BST to MinHeap, also LST<RST
void preOrderMethod(TreeNode* root, vector<int> &v, int &i){
    if(!root) return;
    root->val=v[i++];
    preOrderMethod(root->left, v, i);
    preOrderMethod(root->right, v, i);
}
int main(){
    TreeNode* a=new TreeNode(10);
    TreeNode* b=new TreeNode(5);
    TreeNode* c=new TreeNode(16);
    TreeNode* d=new TreeNode(1);
    TreeNode* e=new TreeNode(8);
    TreeNode* f=new TreeNode(12);
    TreeNode* g=new TreeNode(20);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    preOrder(a);
    cout<<endl;
    
    vector<int> v;
    inOrder(a, v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    } cout<<endl;

    // BFS method
    // bfs(a, v);

    // PreOrder Method
    int i=0;
    preOrderMethod(a, v, i);
    
    preOrder(a);

    return 0;
}