class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<files.size(); i++)
            pq.push(files[i]);
            
        
        int total=0;
        while(pq.size()>1){
            
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            int sum=first+second;
            total +=sum;
            pq.push(sum);
        }
        
        return total;
    }
};