//GFG.
//You will given string and their frequency. you have to return huffman coding.
//if you observe carefully the diagram given. then all characters are there in leaf nodes.
//so first create class with node so that we can create tree.

//then create min heap priority_queue of Node *.
//first push all the values in pq by creating nodes with value. then loop over pq. till size is greater than 1.
//as we pop out..first element is lesser than second element. so we want left element is lesser than right element in tree.
//so first element will be left and seocnd pop element will be right.
//then create one parent from their summation of value and push that parent in pq by creating parent node.

//if you observe..we want preorder traversal. so after size is 1 in pq. top element will be parent i.e root element
//so pass this root node to do preorder traversal and store answer.

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
        bool operator()(Node *a, Node *b){
            
            return a->data > b->data;
        }
};

class Solution
{
	public:
	    void traverse(Node *root, string temp, vector<string>&ans){
	        
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        //go to left.
	        traverse(root->left, temp+'0', ans); //if going left insert char '0'
	        
	        //go to right
	        traverse(root->right, temp+'1', ans); //if going right insert char '1'
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int i=0; i<N; i++){
		        
		        Node *temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1){
		        
		        Node *leftNode = pq.top();
		        pq.pop();
		        
		        Node *rightNode = pq.top();
		        pq.pop();
		        
		        Node *parent = new Node(leftNode->data + rightNode->data);
		        parent->left = leftNode;
		        parent->right = rightNode;
		        
		        pq.push(parent);
		    }
		    
		    Node *root = pq.top();
		    
		    vector<string>ans;
		    string temp="";
		    
		    traverse(root, temp, ans);
		    
		    return ans;
		}
};