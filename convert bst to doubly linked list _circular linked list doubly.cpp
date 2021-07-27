class Solution {
public:
    TreeNode *getright(TreeNode *lefti,TreeNode *&curr){
        if(lefti==curr or lefti==nullptr)
            return lefti;
        while(lefti->right!=nullptr and lefti->right!=curr){
            lefti=lefti->right;
        }
        return lefti;
    }
    TreeNode * treeToDoublyList(TreeNode * root) {
        TreeNode *dummy=new TreeNode (-1);
        TreeNode *prev=dummy;
        TreeNode *curr=root;
        while(curr!=nullptr){
            TreeNode *lefti=curr->left;
            if(lefti==nullptr){
                prev->right=curr;
                curr->left=prev;
                prev=prev->right;
                curr=curr->right;
            }
            else{
                TreeNode* rightmost=getright(lefti,curr);
                if(rightmost->right==nullptr){
                    rightmost->right=curr;
                    curr=curr->left;
                }
                else{
                    rightmost->right=nullptr;
                    prev->right=curr;
                    curr->left=prev;
                    prev=prev->right;
                    curr=curr->right;
                }
            }
        }
        TreeNode *head=dummy->right;
        head->left=dummy->right=nullptr;
        head->left=prev;
        prev->right=head;
        return head;
    }
};
