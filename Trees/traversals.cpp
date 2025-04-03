#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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
void inOrder(TreeNode* root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void postOrder(TreeNode* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
void preOrderIterative(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp=st.top();
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
        cout<<temp->val<<" ";
    }
}
void postOrderIterative(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> v;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp=st.top();
        st.pop();
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
        v.push_back(temp->val);
    }

    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
void inOrderIterative(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> v;
    TreeNode* node=root;

    while(!st.empty() || node){
        if(node){
            st.push(node);
            node=node->left;
        } else {
            TreeNode* temp=st.top();
            st.pop();
            cout<<temp->val<<" ";
            node=temp->right;
        }
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

    preOrder(a);
    cout<<endl;
    inOrder(a);
    cout<<endl;
    postOrder(a);
    cout<<endl;
    preOrderIterative(a);
    cout<<endl;
    inOrderIterative(a);
    cout<<endl;
    postOrderIterative(a);
    cout<<endl;
    
    return 0;
}