class Solution {
public:
    bool dfs(TreeNode* root,long long mini,long long maxi){
        if(root==NULL)
            return true;
        if(maxi<=root->val or mini>=root->val)
            return false;
        bool a=dfs(root->left,mini,root->val);
        bool b=dfs(root->right,root->val,maxi);
        return (a&b);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};



/* mooris inorder method */
class Solution {
public:
    TreeNode* rightt(TreeNode* &leftt,TreeNode* &curr){
        while(leftt->right!=NULL and leftt->right!=curr)
            leftt=leftt->right;
        return leftt;
    }
    bool isValidBST(TreeNode* root) {
        // if(root==NULL or (root->left==NULL and root->right==NULL))
        //     return true;
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        bool flag=true;
        while(curr!=NULL){
            TreeNode* leftt=curr->left;
            if(leftt==NULL){
                if(prev !=NULL and prev->val>=curr->val)
                    flag=false;
                prev=curr;
                curr=curr->right;
            }
            else{
                TreeNode*rightmost=rightt(leftt,curr);
                if(rightmost->right==NULL){
                    rightmost->right=curr;
                    curr=curr->left;
                }
                else{
                     rightmost->right=NULL;
                    if(prev->val>=curr->val)
                        flag=false;
                    prev=curr;
                    curr=curr->right;                 
                    
                }
            }
        }
        return flag;
    }
};