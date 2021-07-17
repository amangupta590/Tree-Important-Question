class Solution {
public:
    int total=0;
    class bst_pair{
        public:
            int maxi=INT_MIN;
            int mini=INT_MAX;
            int sum=0;
            bool isbst=true;
    };
    bst_pair dfs(TreeNode*root){
        if(root==NULL){
            bst_pair base;
            return base;
        }
        bst_pair ll=dfs(root->left); 
        bst_pair rr=dfs(root->right);
        bst_pair n1;
        n1.isbst=false;
        if(ll.isbst and rr.isbst and root->val>ll.maxi and root->val<rr.mini){
            n1.sum=ll.sum+rr.sum+root->val;
            n1.isbst=true;
            n1.maxi=max(root->val,rr.maxi);
            n1.mini=min(root->val,ll.mini);
            total=max(total,n1.sum);
        }
        else{
            n1.maxi=max(root->val,rr.maxi);
            n1.mini=max(root->val,ll.mini);
        }
        return n1;
    }
    int maxSumBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        int hello=dfs(root).sum;
        return total;
    }
};