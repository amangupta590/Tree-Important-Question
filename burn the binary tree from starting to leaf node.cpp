#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
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

void burningnodetree(node*root,int count,node*block){
    if(root==NULL or root==block){
        return ;
    }
    mp[count].push_back(root->val);
    burningnodetree(root->left,count+1,block);
    burningnodetree(root->right,count+1,block);
}
int burningnode(node*root,node*tar){
    if(root==NULL)
        return -1;
    if(root->val==tar->val){
        burningnodetree(root,0,NULL);
        return 1;
    }
    int lt=burningnode(root->left,tar);
    if(lt!=-1){
        burningnodetree(root,lt,root->left);
        return lt+1;
    }
    int rt=burningnode(root->right,tar);
    if(rt!=-1){
        burningnodetree(root,rt,root->right);
        return rt+1;
    }
    return -1;
}
int main() {
    node*root=new node(12);
    root->left=new node(13);
    root->right=new node(10);
    root->right->left=new node(14);
    root->right->right=new node(15);
    root->right->left->left=new node(21);
    root->right->left->right=new node(24);
    root->right->right->left=new node(22);
    root->right->right->right=new node(23);
    node* target=new node(14);
    int temp=burningnode(root,target);
    for(auto ss:mp){
        cout<<ss.first<<" : ";
        vector<int>arr=ss.second;
        for(int ff:arr){
            cout<<ff<<" ";
        }
        cout<<endl;
    }
}
