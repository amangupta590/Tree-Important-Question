class Solution {
  public:
      class vpair{
    	public:
    		Node *node=NULL;
    		int vl=0;
    		vpair(Node * node,int vl){
    			this->node=node;
    			this->vl=vl;
    		}
        };
    void shadow(Node *root,int vl,vector<int>&minmax){
    	if(root==NULL)
    		return;
    	minmax[0]=min(minmax[0],vl);
    	minmax[1]=max(minmax[1],vl);
    	shadow(root->left,vl-1,minmax);
    	shadow(root->right,vl+1,minmax);
    }
    vector <int> bottomView(Node *root) {
        vector<int>minmax(2,0);
	if(root==NULL)
		return {};
	shadow(root,0,minmax);
	int width=minmax[1]-minmax[0]+1;
	queue<vpair>q;
	vector<int>ans(width,0);
	q.push(vpair(root,abs(minmax[0])));
	while(!q.empty()){
		int n=q.size();
		while(n--){
			vpair p=q.front();
			q.pop();
			Node * temp=p.node;
			int vl=p.vl;
			ans[vl]=temp->data;
			if(temp->left)
				q.push({temp->left,vl-1});
			if(temp->right)
				q.push({temp->right,vl+1});
		}
	}
	return ans;
        // Your Code Here
    }
};