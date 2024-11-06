
//gfg->reverse level order.
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        if(temp) ans.push_back(temp->data);
        q.pop();
        if(temp->right) q.push(temp->right); //first insert right..then left.
        if(temp->left) q.push(temp->left);
    }
    
    reverse(ans.begin(),ans.end()); //at the end just reverse the ans.
    return ans;
}