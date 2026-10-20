class Solution {
  public:
   
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
       
        unordered_map<int,int>ladMap;
        
        for(int i=0; i<lad.size(); i+=2){
            ladMap[lad[i]] = lad[i+1];
        }
        
        unordered_map<int,int>snMap;
        
        for(int i=0; i<sn.size(); i+=2){
            snMap[sn[i]] = sn[i+1];
        }
        
        vector<int>dist(n*n+1,INT_MAX);
        
        int start = 1, end = n*n;
        queue<int>q;
        q.push(start);
        dist[start]=0;
        
        while(!q.empty()){
            
            int pos = q.front();
            q.pop();
            
            if(pos==end) return dist[pos];
            
            
            for(int i=1; i<=6; i++){
                int newPos = pos+i;
                
                if(newPos > end) break;
    
                if(snMap.find(newPos) != snMap.end())
                    newPos = snMap[newPos];
                
                else if(ladMap.find(newPos) != ladMap.end())
                    newPos = ladMap[newPos];
                    
                int newDist = dist[pos] + 1;
                
                if(newDist < dist[newPos]){
                    dist[newPos] = newDist;
                    q.push(newPos);
                }
            }
        }
        
    
        if(dist[end]==INT_MAX) return -1;
        return dist[end];
    }
};