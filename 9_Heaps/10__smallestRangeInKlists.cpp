//Smallest range in K lists
//GFG

//Optimised Approach: TC-O(n*klogk) SC-O(k)
//Push first element of all sub array into the min heap
//after this loop till min heap's size equal to k, becuase if we not able to insert next element then we need to stop that time size won't equal to k.
class node{ //creating node class so that we can track for next element as well
    public:
    int data;
    int row;
    int col;
    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compareMin{ //compare class for comparing
    public:
    bool operator()(node *a, node *b){
        return a->data > b->data;
    }
};

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    //creating priority queue to get min element and also to track next element in array after popping out min element.
    priority_queue<node *, vector<node*>, compareMin> minHeap; 
    
    int miniAns = INT_MAX; 
    int maxiAns = INT_MIN;
    int smallDiff = INT_MAX;  //initially smalldiff will be maximum as possible

    //processing first k element i.e first element of every sub array.
    for(int i = 0; i<k; i++){ 
        node *info = new node(arr[i][0], i, 0); //creating new node.
        minHeap.push(info); //pushing that into the min heap
        miniAns = min(arr[i][0], miniAns);
        maxiAns = max(arr[i][0], maxiAns); //tracking for miniAns and maxiAns
    }
    
    //creating mini and maxi..to track current mini and maxi.
    int mini = miniAns, maxi = maxiAns; //creating another two variable
    while(minHeap.size() == k){ //looping till equals to k because..if size is less than k
    //that means we're not able to push element in heap..i.e one array is finished..so we cannot create range..then no need to enter again in this loop.
        
        node *smallNode = minHeap.top(); //getting top node of min heap
        minHeap.pop(); //pooping out that node
        
        int row = smallNode->row; //getting row of current element
        int col = smallNode->col; //and also column
        
        mini = smallNode->data; //updating current mini element 
        
        int diff = maxi - mini; //getting current difference of current range
        if(diff < smallDiff){ //if currnet range difference less than smallest range difference then update small range diff.
            smallDiff = diff; //updating smalldiff..as this range can be possible answer.
            miniAns = mini;
            maxiAns = maxi; //also update mini and maxi ans.
        }
        
        if(col+1 < n){ //if next element is present in array of current eleemnt
            node *next = new node(arr[row][col+1], row, col+1); //then create node for current element
            minHeap.push(next); //push in heap
            maxi = max(maxi, arr[row][col+1]); //update maxi.
        }   
    }
    
    return {miniAns, maxiAns}; //return final range.
}