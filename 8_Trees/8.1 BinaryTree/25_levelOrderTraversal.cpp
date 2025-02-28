//gfg-> level order traversal.

//Approach. Tc-O(N) Sc-O(N)
vector<int> levelOrder(Node* root)
{
    queue<Node *> q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        ans.push_back(temp->data);
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;
}


//Now question has change so. //level wise store answer.
 vector<vector<int>> levelOrder(Node *root) {
    queue<Node *> q;
    vector<vector<int>>ans;
    q.push(root);
    while(!q.empty()){   
        int size=q.size();
        vector<int>res;
        
        for(int i=0; i<size; i++){
            Node *temp = q.front();
            res.push_back(temp->data);
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        } 
        ans.push_back(res);
    }
    return ans;
}