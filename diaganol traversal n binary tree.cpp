vector<int> diagonal(Node *root)
{
   if(root==NULL)
    return {};
   queue<Node*>q;
   q.push(root);
   vector<int>ans;
   while(!q.empty()){
       int n=q.size();
       while(n--){
           Node *temp=q.front();
           q.pop();
           while(temp!=NULL){
               ans.push_back(temp->data);
               if(temp->left)
                q.push(temp->left);
               temp=temp->right;
           }
       }
   }
   return ans;
}