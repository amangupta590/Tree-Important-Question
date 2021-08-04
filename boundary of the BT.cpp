class Solution {
public:
     vector<int>v;
    void printleft(TreeNode * root){
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL){
            return ;
        }
        v.push_back(root->val);
        if(root->left)
            printleft(root->left);
        else if(root->right)
            printleft(root->right);
    }
    void printright(TreeNode *root){
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL)
            return ;
        if(root->right){
            printright(root->right);
            v.push_back(root->val);
            return ;
        }
        if(root->left){
            printright(root->left);
            v.push_back(root->val);
            return ;
        }
    }
    void printleaf(TreeNode *root){
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
            return ;
        }
        printleaf(root->left);
        printleaf(root->right);
        return ;
    }
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        //vector<int>v;
        if(root==NULL)
            return v;
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
            return v;
        }
        v.push_back(root->val);
        printleft(root->left);
        printleaf(root);
        printright(root->right);
        return v;
    }
};