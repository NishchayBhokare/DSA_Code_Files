//gfg-> level order traversal.

//Approach. Tc-O(N) Sc-O(N)
vector<int> levelOrder(Node* root)
    {
        queue<Node *> q;
        vector<int>ans;
        q.push(root);
        // q.push(NULL);
        while(!q.empty()){
            Node *temp = q.front();
            if(temp) ans.push_back(temp->data);
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return ans;
    }