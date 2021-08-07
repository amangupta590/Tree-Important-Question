#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node*left=NULL;
        Node*right=NULL;
        Node(int val){
            this->val=val;
        }
};
class v_pair{
    public:
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int tc=0;
        bool poss=true;
};
v_pair dfs(Node*root){
    if(root==NULL){
        v_pair base;
        return base;
    }
    v_pair l=dfs(root->left);
    v_pair r=dfs(root->right);
    v_pair n1;
    if(root->val>l.maxi and root->val<r.mini and l.poss and r.poss){
        n1.mini=min(root->val,l.mini);
        n1.maxi=max(root->val,r.maxi);
        n1.tc=(l.tc+r.tc)+1;
        return n1;
    }
    else{
         n1.mini=min(root->val,l.mini);
        n1.maxi=max(root->val,r.maxi);
        n1.tc=(l.tc+r.tc);
        n1.poss=false;
        return n1;
    }
    return n1;
}
int main() {
    Node* root = new Node(11);
    root->left = new Node(8);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left = new Node(9);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(6);
    v_pair hello=dfs(root);
    cout<<hello.tc<<endl;
}
