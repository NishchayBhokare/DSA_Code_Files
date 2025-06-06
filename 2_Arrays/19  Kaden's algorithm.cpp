//GFG.
//we have to  find the maximum sum of a subarray. 
// array contains +ve and -ve elements.
//Approach 1: optimised Appraoch. Kaden's algo.
int maxSubarraySum(vector<int> &arr) {
    
    int maxSum=INT_MIN, sum=0, n=arr.size();
    
    for(int i=0; i<n; i++){
        
        sum+=arr[i];
        maxSum = max(maxSum,sum);
        
        if(sum < 0) sum=0; //if current sum is lesser than zero..then no need to take it na. because it will anyway..reduce total sum.
        //so reset sum to 0.
    }
    
    return maxSum;
}
    

//We will tell to the interviewer if they ask for largest subarray elements.
int maxSubarraySum(vector<int> &arr) {
    
    int maxSum=INT_MIN, sum=0, n=arr.size(), mainStart=0, mainEnd=0;
    int start = 0, end=0;
    
    for(int i=0; i<n; i++){
        
        if(sum==0) start=i; //alsways when sum will be 0. we will start.
        
        sum+=arr[i];
        
        if(sum > maxSum){
            maxSum = max(maxSum,sum);
            mainStart=start; 
            mainEnd=i; //and every time when we're updating maxsum. please update mainStart to start and mainEnd to i.
        }
        
        if(sum < 0)
            sum=0;
        
    }
    return maxSum;
}


//Approach 2: brute force approach. generate all subarrays.
int maxSubarraySum(vector<int> &arr) {
        
    int maxSum=INT_MIN, sum=0, n=arr.size();
    
    for(int i=0; i<n; i++){
        
        sum=0;
        
        for(int j=i; j<n; j++){
            
            sum+=arr[j];
            
            maxSum = max(maxSum,sum);
        }
    }
    
    return maxSum;
}
Hi Team,

I am Nishchay Bhokare, I have 1.7 years of experience at TCS, specializing in Angular, TypeScript, Node.js, Express.js, MongoDB, and REST APIs, with a focus on building scalable and accessible web applications.

Additionally, I am proficient in Data Structures and Algorithms (DSA) and have solved 500+ problems on platforms like GeeksforGeeks, CodeStudio, and LeetCode.

I have attached my resume for your reference.

Email: nishchay1602@gmail.com

If you think I would be a good fit, I would like to discuss further about this good opportunity. Thank you in advance! 

Thank you in advance!



Best regards,

Nishchay