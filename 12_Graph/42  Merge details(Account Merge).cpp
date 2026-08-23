//Leetcode - Account Merge

class DisjointSet{
    public:
        vector<int>parent;
        vector<int>rank;
        
        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n);
            
            for(int i = 0; i<n; i++)
                parent[i]=i;
        }
        
        int findParent(int node){
            
            if(node == parent[node])
                return node;
            
            return parent[node] = findParent(parent[node]);
        }
        
        
        void makeUnion(int u, int v){
            
            int uP = findParent(u);
            int vP = findParent(v);

            if(uP == vP) return;

            if(rank[uP] == rank[vP]){
                parent[vP] = uP;
                
                rank[uP]++;
            }
            else if(rank[uP] > rank[vP]){
                parent[vP] = uP;
            }
            else{
                parent[uP] = vP;
            }
        }
};

//Step 1 : creation of mapping and skipping duplicate strings..by making union.
//Step 2 : merged all mails in merged mails array which will be stored like 0 -> first student all mails, 1-> second stud. etc.
//Step 3 : Create answer vector..and store all this merged string with it's studnet name in answer vector.
class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
         int n = details.size();
        
        // creation of mapping
        unordered_map<string,int> mapping;
        DisjointSet ds(n);

        for(int i = 0; i<n; i++){
            for(int j = 1; j<details[i].size(); j++){
                string str = details[i][j];
                
                if(mapping.find(str) == mapping.end()){ //checking whther this email already camer or not
                    // if not then assign index to it and if yes..then go for union. 
                    mapping[str] = i;
                }
                
                else{ //if already this string is present..th   en existing string index is parent for this new string index.
                    
                    int u = mapping[str];
                    int v = i;
                    ds.makeUnion(v,u);
                }
            }
        }
        
        
        //step 2: creation of answer without addition of studnet name. only adding mails. There can be empty vector.
        //so for that in next step we're creating answer.
        vector<vector<string>>mergedMails(n);
        for(auto i:mapping){
            string mail = i.first;
            int index = ds.findParent(i.second);

            mergedMails[index].push_back(mail);
        }

        //step 3: creation of answer.
        vector<vector<string>>ans;

        for(int i = 0; i<n; i++){   
            if(mergedMails[i].size() == 0) continue; 
            //if ith student get's merged then skip for this student.

            sort(mergedMails[i].begin(), mergedMails[i].end()); //first sort all mails for particualr student.

            vector<string>temp; //creation of temp vector of string.

            string student = details[i][0];
            temp.push_back(student); //first add student.

            for(auto mails:mergedMails[i]){ //then add remaining it's mails.
                temp.push_back(mails);
            }

            ans.push_back(temp); //finally push temp in asnwer vector.
        }

        return ans; //and return final answer.
    }
};


//slight chagnes in below solution. 
class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        // code here
        
        int n = arr.size();
        DisjointSet ds(n);
        
        unordered_map<string,int>mapping;
        
        //creation of mapping is done.
        for(int i=0; i<n; i++){
            for(int j=1; j<arr[i].size(); j++){
                
                if(mapping.find(arr[i][j]) == mapping.end())
                    mapping[arr[i][j]] = i;
                
                else{
                    
                    int u = mapping[arr[i][j]];
                    int v = i;
                    
                    ds.makeUnion(u,v);
                }
            }
        }
        
        unordered_map<int,vector<string> > mergeString;
        
        for(auto [email,index]:mapping){
            
            int ind = ds.findParent(index);
            
            mergeString[ind].push_back(email);
            sort(mergeString[ind].begin(), mergeString[ind].end());
        }
        
        vector<vector<string>>ans;
        
        for(auto [index,strVec]:mergeString){
            
            vector<string>temp;
            temp.push_back(arr[index][0]);
            
            for(auto str:strVec)
                temp.push_back(str);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};

