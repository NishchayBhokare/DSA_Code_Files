//Approach 1: Simple and optimised approach.
class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        
        int sum1 = accumulate(s1.begin(),s1.end(),0);
        int sum2 = accumulate(s2.begin(),s2.end(),0);
        int sum3 = accumulate(s3.begin(),s3.end(),0);
        
        
        int top1=0, top2=0, top3=0;
        
        while(sum1>0 and sum2>0 and sum3>0){
            
            if(sum1==sum2 and sum2==sum3) return sum1;
            
            else if(sum1>=sum2 and sum1>=sum3)
                sum1-=s1[top1++];
            
            else if(sum2>=sum1 and sum2>=sum3)
                sum2-=s2[top2++];
            
            else 
                sum3-=s3[top3++]; 
        }
        
        return 0;
    }
};