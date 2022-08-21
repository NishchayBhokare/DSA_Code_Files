//Example for power set of given string.

#include<bits/stdc++.h>
using namespace std;	

//Approach 1: using recursion TC- O(2^n) SC- O(2^n)
	vector<string> ans; //Globally declared.
    void solve(string s,string curr,int i){
        if(i==s.size()){ //base case when i becomes equal to size of string that means we reach to end. so push curr to ans and return to calling function.
            ans.push_back(curr);
            return;
        }

        //taking ith element
        solve(s,curr+s[i],i+1);
        
        //not taking ith element
        solve(s,curr,i+1);
        
        return;
    }
    vector<string> AllPossibleStrings(string s){
    
     solve(s,"",0);
     sort(ans.begin(),ans.end()-1); //sorting from beginning to end -1, cause end element is "" which we do'nt want in power set.
     return ans;
    }
	
	
//Approach 2: Using Bit Manipulation TC- O(2^n.logn) SC- O(2^n*n)
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int sequences=pow(2,s.size());//total sequences can be pow of 2 raise to size-1.
		    for(int i=1;i<sequences;i++){ //looping from 1 to 7.
		        int x=i,bitPos=0; //to iterate over 1 to 7 elements, assign i to x.
		        string sub=""; 
		        while(x){ //lopping till x not become 0.
		            if(x & 1) sub=sub+s[bitPos]; //if bit is set then add sub string which stands on bitPos. in string s. 
		            x=x>>1; //right shift one time so that number will get reduce.
		            bitPos++; //incrementing bitpos.
		        }
		        ans.push_back(sub); //after iterting over a particular decimal no. add whatever substring created, in ans.
		    }
		    sort(ans.begin(),ans.end()); //after iterating over all decimal no. sort ans. cause we want answer in lexicographical form.
		    return ans;
		}
// Analogy behind approach 2:
	//for eg. string s="abc", total sequences are 7. so you can observe binary Rep. of decimal no. 1 to 7.
	//for 1- 001, 2- 010 , 3- 011, 4- 100, 5- 101, 6- 110, 7- 111.
	//so when we get set bit i.e 1, then according to pos. of that set we will add sub. string from s to curr.
	//like in case decimal no. 2, we have set bit on 1st pos. so we will add 'b' to curr cause 'b' also stands on 1 st pos. in string s. (indexing from 0).
	//so we will iterate over 1 to 7 decimal no. x=i.