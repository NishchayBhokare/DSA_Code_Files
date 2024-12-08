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
                
                if(mapping.find(str) == mapping.end()){ //first time inserting.
                    mapping[str] = i;
                }
                
                else{ //if already this string is present..then existing string index is parent for this new string index.
                    
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
            if(mergedMails[i].size() == 0) continue; //if ith student get's merged then skip for this student.

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