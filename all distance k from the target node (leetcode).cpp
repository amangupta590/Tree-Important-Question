class Solution {
public:
    vector<int>ans;
    void binaryprint(TreeNode* root,int count,TreeNode* block,int k){
        if(root==NULL or root==block)
            return ;
        if(k==count){
            ans.push_back(root->val);
            return ;
        }
        binaryprint(root->left,count+1,block,k);
        binaryprint(root->right,count+1,block,k);
    }
    int binarytree(TreeNode* root,TreeNode* tar,int k){
        if(root==NULL)
            return -1;
        if(root==tar){
            binaryprint(root,0,NULL,k);
            return 1;
        }
        int lt=binarytree(root->left,tar,k);
        if(lt!=-1){
            if(lt==k){
                ans.push_back(root->val);
            }
            else{
                binaryprint(root,lt,root->left,k);
            }
            return lt+1;
        }
        int rt=binarytree(root->right,tar,k);
        if(rt!=-1){
            if(rt==k){
                ans.push_back(root->val);
            }
            else{
                binaryprint(root,rt,root->right,k);
            }
            return rt+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        if(root==NULL)
            return ans;
        int temp=binarytree(root,tar,k);
        return ans;       
        
    }
};