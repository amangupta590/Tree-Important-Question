class Solution {
public:
    TreeNode* dfs(TreeNode* root,TreeNode*p,TreeNode*q){
        if(root==NULL)
            return NULL;
        TreeNode* lt=dfs(root->left,p,q);
        TreeNode* rt=dfs(root->right,p,q);
        if(lt!=NULL and rt!=NULL)
            return root;
        if(root==p or root==q)
            return root;
        if(lt==NULL and rt==NULL){
            if(root==p or root==q)
                return root;
            return NULL;
        }
        if(lt==NULL)
            return rt;
        return lt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        TreeNode* temp=dfs(root,p,q);
        return temp;        
    }
};
