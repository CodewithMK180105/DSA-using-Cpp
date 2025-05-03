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

int noOfNodes(TreeNode* root){
    if(!root) return 0;
    return 1+noOfNodes(root->left)+noOfNodes(root->right);
}

bool isCBT(TreeNode* root, int size){
    queue<TreeNode*> q;
    q.push(root);
    int count=0;

    while(count!=size){
        TreeNode* temp=q.front();
        q.pop();
        count++;
        if(temp) q.push(temp->left);
        if(temp) q.push(temp->right);
    }

    while(!q.empty()){
        if(q.front()){
            return false;
        }
        q.pop();
    }
    return true;
}

bool maxHeapValPropertySatisfied(TreeNode* root){
    if(root->left && root->left->val > root->val) return false;
    if(root->right && root->right->val > root->val) return false;
    if(root->left) return maxHeapValPropertySatisfied(root->left);
    if(root->right) return maxHeapValPropertySatisfied(root->right);
    return true;
}
int main(){
    TreeNode* a=new TreeNode(10);
    TreeNode* b=new TreeNode(5);
    TreeNode* c=new TreeNode(6);
    TreeNode* d=new TreeNode(1);
    TreeNode* e=new TreeNode(4);
    TreeNode* f=new TreeNode(3);
    TreeNode* g=new TreeNode(2);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    // c->left=f;
    c->right=g;

    int size=noOfNodes(a);
    cout<<"size is "<<size<<endl;

    cout<<isCBT(a, size)<<endl;
    cout<<maxHeapValPropertySatisfied(a)<<endl;
    if(isCBT(a, size) && maxHeapValPropertySatisfied(a)){
        cout<<"It is a Max Heap";
    } else cout<<"Not a Max Heap";
    return 0;
}