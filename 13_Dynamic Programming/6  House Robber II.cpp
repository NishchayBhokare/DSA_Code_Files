////code studio.
//This question is similar to previous..just change is..first and last elmement is also adjacent element.
///so we have to exclude it and calcuate answer. so first calculate answer by excluding first and then 
//calculate by excluding last.

// Using Memorization
long long int solve(int n, vector<int>&temp, vector<long long int>&dp){

    if(n == 0) return temp[0];
    if(n == 1) return max(temp[0],temp[1]);

    if(dp[n] != -1) return dp[n];

    //take current element.
    long long int take = temp[n] + solve(n-2,temp,dp);

    //not take current element.
    long long int notTake = solve(n-1,temp,dp);

    return dp[n] = max(take,notTake);
}

long long int houseRobber(vector<int>& arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];
    
    vector<int>temp1, temp2;

    //creation of temp vector..first vector excluded first element and second vector 
    //excluded last element.
    for(int i = 0; i<n; i++){
        if(i != 0) temp1.push_back(arr[i]);
        if(i != n-1) temp2.push_back(arr[i]);
    }

    n = temp1.size();//updated n as we skip one one element for both the temp arrays.
    vector<long long int>dp1(n,-1), dp2(n,-1);

    long long int firstAns = solve(n-1,temp1,dp1); //calculate first
    long long int secondAns = solve(n-1,temp2,dp2); //second.

    return max(firstAns,secondAns); //take max of it.
}





                                         //Tabulation.

long long int solve(int n, vector<int>&temp, vector<long long int>&dp){

    dp[0] = temp[0];
    dp[1] = max(temp[0],temp[1]);

    for(int i = 2; i<n; i++){

        //take current element.
        long long int take = temp[i] + dp[i-2];

        long long int notTake = dp[i-1];

        dp[i] = max(take,notTake);
    }

    return dp[n-1];   
}

long long int houseRobber(vector<int>& arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];
    
    vector<int>temp1, temp2;

    //creation of temp vector..first vector excluded first element and second vector 
    //excluded last element.
    for(int i = 0; i<n; i++){
        if(i != 0) temp1.push_back(arr[i]);
        if(i != n-1) temp2.push_back(arr[i]);
    }

    n = temp1.size();//updated n as we skip one one element for both the temp arrays.
    vector<long long int>dp1(n,-1), dp2(n,-1);

    long long int firstAns = solve(n,temp1,dp1);
    long long int secondAns = solve(n,temp2,dp2);

    return max(firstAns,secondAns);
}




                                        //Space Optimization.
long long int excludeFirst(vector<int>&arr){
    int n = arr.size();

    if(n == 1) return arr[n];

    long long int prevOfPrev = arr[1];
    long long int prev = max(arr[1],arr[2]);

    for(int i = 3; i<n; i++){ //here starting from 3. because size for 1 is handled in int main funciton.
    //size for two need to handle here..i.e n == 1 so starting from 3.

        //take current element.
        long long int take = arr[i] + prevOfPrev;

        long long int notTake = prev;

        long long int curr = max(take,notTake);
        prevOfPrev = prev;
        prev = curr;
    }

    return prev;   
}


long long int excludeLast(vector<int>&arr){
    int n = arr.size()-1; //excluding last element.

    if(n==1) return arr[0];

    long long int prevOfPrev = arr[0];
    long long int prev = max(arr[0],arr[1]);

    for(int i = 2; i<n; i++){

        //take current element.
        long long int take = arr[i] + prevOfPrev;

        long long int notTake = prev;

        long long int curr = max(take,notTake);
        prevOfPrev = prev;
        prev = curr;
    }

    return prev;   
}

long long int houseRobber(vector<int>& arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];


    long long int firstAns = excludeFirst(arr); //call for exclude first element.
    long long int secondAns = excludeLast(arr); //include last element.

    return max(firstAns,secondAns);
}