class Solution {
public:
    TreeNode*find(TreeNode*root){
        if(root->left==NULL)
            return root;
        while(root->left!=NULL)
            root=root->left;
        return root;
    }
    TreeNode*dfs(TreeNode*root,int key){
        if(root==NULL)
            return NULL;
        if(root->val==key){
            if(root->left==NULL and root->right==NULL)
                return NULL;
            else if(root->right==NULL)
                return root->left;
            else if(root->left==NULL)
                return root->right;
            else{
                TreeNode*f=find(root->right);
                swap(f->val,root->val);
                root->right=dfs(root->right,key);
            }   
            return root;
        }
        if(root->val>key)
            root->left=dfs(root->left,key);
        else 
            root->right=dfs(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root,key);
    }
};