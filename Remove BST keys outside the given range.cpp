node* dfs(node*root,int min,int max){
    if(root==NULL)
        return NULL;
    root->left=dfs(root->left,min,max);
    root->right=dfs(root->right,min,max);
    if(root->val<min){
        node*lchild=root->right;
        delete root;
        return lchild;
    }
    if(root->val>max){
        node* rchild=root->left;
        delete root;
        return rchild;
    }
    return root;
}