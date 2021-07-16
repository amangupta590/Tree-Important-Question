// preorder and inorder construct tree ///
class Solution {
public:
    unordered_map<int,int>mp;
    TreeNode* dfs(vector<int>&pre,vector<int>&in,int ps,int pe,int is,int ie){
        if(ps>pe)
            return NULL;
        int idx=mp[pre[ps]];
        int rightsize=ie-idx;
        int leftsize=idx-is;
        TreeNode* root=new TreeNode(pre[ps]);
        root->left=dfs(pre,in,ps+1,ps+leftsize,is,idx-1);
        root->right=dfs(pre,in,ps+leftsize+1,pe,idx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        for(int i=0;i<n;i++)
            mp[in[i]]=i;
        return dfs(pre,in,0,n-1,0,n-1);
    }
};


/// postorder and inorder to make the binary tree
class Solution {
public:
    unordered_map<int,int>mp;
    TreeNode* dfs(vector<int>&inorder ,vector<int>&postorder,int instart,int inend,int poststart,int postend){
        if(instart>inend)
            return NULL;
        int indexii=mp[postorder[postend]];
        TreeNode*root=new TreeNode(postorder[postend]);
        int leftsize=indexii-instart;
        int rightsize=inend-indexii;
        root->left=dfs(inorder,postorder,instart,indexii-1,poststart,poststart+leftsize-1);
        root->right=dfs(inorder,postorder,indexii+1,inend,poststart+leftsize,postend-1);
        return root;        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n=po.size();
        for(int i=0;i<n;i++)
            mp[in[i]]=i;
        return dfs(in,po,0,n-1,0,n-1);
        
        
    }
};

//  Construct Binary Tree from Preorder and Postorder Traversal

class Solution {
public:
    unordered_map<int,int>mp;
    TreeNode*dfs(vector<int>&pre,vector<int>&post,int ps,int pe,int pos,int poe){
        if(ps>pe)
            return NULL;
        TreeNode* root=new TreeNode(pre[ps]);
        if(ps==pe)
            return root;
        int idx=mp[pre[ps+1]];
        int lefti=idx-pos+1;
        root->left=dfs(pre,post,ps+1,ps+lefti,pos,pos+idx-1);
        root->right=dfs(pre,post,ps+lefti+1,pe,idx+1,poe-1);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=post.size();
        for(int i=0;i<n;i++)
            mp[post[i]]=i;
        return dfs(pre,post,0,n-1,0,n-1);
    }
};