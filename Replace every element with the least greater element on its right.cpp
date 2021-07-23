//https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node*left;
        Node*right;
        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
Node* insertion(Node*&root,int data,Node*&succ){
    if(root==NULL){
        Node*newii=new Node(data);
        return newii;
    }
    if(root->val<data){
        root->right=insertion(root->right,data,succ);
    }
    else{
        succ=root;
        root->left=insertion(root->left,data,succ);
    }
    return root;
}
void dfs(vector<int>&arr,int n){
    Node*root=NULL;
    for(int i=n-1;i>=0;i--){
        Node*succ=NULL;
        root=insertion(root,arr[i],succ);
        if(succ==NULL)
            arr[i]=-1;
        else{
            arr[i]=succ->val;
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dfs(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
