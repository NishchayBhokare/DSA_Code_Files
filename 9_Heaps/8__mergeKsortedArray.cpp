//Merge k Sorted Arrays
//GFG

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Most optimised approach TC-O(K2logk) SC-O(K)
//Analogy: pushing first element of all sub arrays in priority queue.
// we are creating queue of node type so that we can track next element in sub array
class node{  //creating class of node type
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
    
    class compare{ //instead writing greater<int> we need to write this class. understand structure plz.
        public:
        bool operator() (node *a, node*b){
            return a->data > b->data;
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans; 
        priority_queue<node *,vector<node*>, compare> pq; //creating priority queue of node class type
        
        for(int row=0,col=0; row<K; row++){ //here incrementing only row.
            node *temp = new node(arr[row][0],row,col); //creating temp of class node type
            pq.push(temp);//pushing all the first elements of all sub array.
        }
        
        while(pq.size() != 0){ //looping till size is not equals to 0
            node * temp = pq.top(); //getting top most node
            ans.push_back(temp->data); //pushing data of temp in ans
            pq.pop(); //popping out that top most node
            
            int row = temp->row;
            int col = temp->col; //getting row and col
          
            if(col+1 < K){ //checking next element of rowth array (i.e column index) is in range of k or not.
                node *next = new node(arr[row][col+1],row,col+1); //if yes, then creating node for next element.
                pq.push(next); //and storing that next node in priority queue
            }    
        }
        
        return ans; //returning answer.
    }


//Approach 2: Using Priority queue. TC-O(K2.logk2) SC-O(K2);
//pushing all the elements of priority queue.
//then getting one by one smallest element by popping from priority queue.
vector<int> mergeKArrays(vector<vector<int> > arr, int K)
{
    vector<int> ans; 
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            pq.push(arr[i][j]);
        }
    }
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}


//Approach 3: Using map. TC-O(K2.logk2) SC-O(K2);
//pushing elements in map while incrementing its count.
//and traversing over map, while count of particular element not gets 0, till that time pushing that element in answer vector.
 vector<int> mergeKArrays(vector<vector<int> > arr, int K)
{
    vector<int> ans; 
    map <int,int> mp;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            int element  = arr[i][j];
            mp[element]++;
        }
    }
    
    for(auto j : mp){
        while(j.second > 0){
            ans.push_back(j.first);
            j.second = j.second - 1;
        }
    }
    
    return ans;
}


//Approach 4: Using sorting TC-O(K2.logK2) SC-O(K2)
 vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            ans.push_back(arr[i][j]); //pushing all the elements in ans vector.
        } 
    }
    
    sort(ans.begin(),ans.end()); //and sorting ans vector
    
    return ans;
}