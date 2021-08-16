#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int val;
        node*left;
        node*right;
        node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
int find(node*root,node*block){
    if(root==NULL or root==block)
        return INT_MAX/2;
    if(root->left==NULL and root->right==NULL)
        return 0;
    return 1+min(find(root->left,block),find(root->right,block));
}
int dfs(node*root,int tar,int &maxi){
    if(root==NULL)
        return -1;
    if(root->val==tar){
        int k=find(root,NULL);
        maxi=min(maxi,k);
        return 1;
    }
    int ll=dfs(root->left,tar,maxi);
    if(ll!=-1){
        maxi=min(maxi,ll+find(root,root->left));
        return 1+ll;
    }
    int rr=dfs(root->right,tar,maxi);
    if(rr!=-1){
        maxi=min(maxi,rr+find(root,root->right));
        return 1+rr;
    }
    return -1;
}
int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(5);
    root->right->right=new node(6);
    root->right->left->left=new node(7);
    root->right->right->right=new node(19);
    root->right->right->right->left=new node(11);
    root->right->left->left->left=new node(9);
    root->right->left->left->right=new node(10);
    int target=2;
    int maxi=INT_MAX;
    int temp=dfs(root,target,maxi);
    cout<<maxi<<endl;
}
