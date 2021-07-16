//morris traversal
class Solution {
public:
    TreeNode* find(TreeNode*leftii,TreeNode* curr){
        if(leftii==curr or leftii==NULL)
            return leftii;
        //TreeNode*hello=leftii;
        while(leftii->right!=NULL and leftii->right!=curr){
            leftii=leftii->right;
        }
        return leftii;
    }
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            TreeNode* lefti=curr->left;
            if(lefti==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* rightmodt=find(lefti,curr);
                // making the thread
                if(rightmodt->right==NULL){
                    rightmodt->right=curr;
                    curr=curr->left;
                }
                // break the thread
                else{
                    rightmodt->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};