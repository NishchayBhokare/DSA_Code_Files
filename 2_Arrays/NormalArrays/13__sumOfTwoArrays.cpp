// Example for Sum of two arrays.
// coding ninjas, GFG
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include<algorithm>
using namespace std;

//Approach 1: Using bitmanipulation technique. TC-O(n) Sc-O(1).
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
    
    int num1=0, num2=0, num3=0;
    for(auto i:a) num1 = (num1 * 10) + i; //storing number in num 1 i.e if array have elements 1,4,5 then num1 will be 145.
    for(auto j:b) num2 = (num2 * 10) + j; //similarly for num2.
    
    num3 = num1 + num2; //Adding both number in num3.
    vector<int> ans;
    while(num3){
        int digit = num3 % 10;
        ans.push_back(digit); //by extracting every digit from num3, pushing that digit in ans vector.
        num3 = num3/10;
    }
    reverse(ans.begin(),ans.end()); //reversing that vector, cause we extract right most digit.
    return ans;
}


//Approach 2: Using sum and carry. TC-O(n) Sc-O(1).
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
  
    int i=n-1; //we're looping from back in both array.
    int j=m-1;
    int sum=0,carry=0,digit;
    vector<int> ans;
    while( i>=0 && j>=0){ //for normal case when both ith and jth element is present.
        sum = a[i] + b[j] + carry; //adding ith and jth element also carry in sum.
        carry = sum / 10; //to calculate carry if present, then do sum divide by 10 cause if sum is 18 then 18/10 will be 1, which is our carry.
        digit = sum  % 10; //no need to write if block like sum > 9 or not, because modulus always gives remainder..e right most digit do sum mod with 10.
        ans.push_back(digit); //push that digit in ans.
        i--; j--; //decrementing i and j.
    }
    
    while( i>=0 ){ //suppose when jth array finished but ith array still remain. then push those ith arrays element in ans.
        sum = a[i] + carry; //adding ith element with carry in sum.
        carry = sum / 10; //calculating carry similarly in above while loop.
        digit  = sum % 10; //getting digit.
        ans.push_back(digit); //pushing in ans.
        i--; //decrement i
    }
    
    while( j>=0 ){ //similarly for jth array, if elements are still remain.
        sum = b[j] + carry;
        carry = sum / 10;
        digit  = sum % 10;
        ans.push_back(digit);
        j--;
    }
    
    if(carry){ //at the end if any carry is present then push it in ans vector.
        ans.push_back(carry);
    }
    reverse(ans.begin(),ans.end()); //reverse vector. becuase we loop from back of a,b array and pushed in front of ans.
    return ans;
    
}





//GFG Version - Just need to remove leading zeros.
//Approach - Using sum and carry. TC-O(n) Sc-O(1).

  string calc_Sum(int *a,int n,int *b,int m){
    int i=n-1; //we're looping from back in both array.
    int j=m-1;
    int sum=0,carry=0,digit;
    string ans="";
    while( i>=0 && j>=0){ //for normal case when both ith and jth element is present.
        sum = a[i] + b[j] + carry; //adding ith and jth element also carry in sum.
        carry = sum / 10; //to calculate carry if present, then do sum divide by 10 cause if sum is 18 then 18/10 will be 1, which is our carry.
        digit = sum  % 10; //no need to write if block like sum > 9 or not, because modulus always gives remainder..e right most digit do sum mod with 10.

        char ch = digit + '0'; //convert integer num to character.
        ans.push_back(ch); //push that digit in ans.
        i--; j--; //decrementing i and j.
    }
    
    while( i>=0 ){ //suppose when jth array finished but ith array still remain. then push those ith arrays element in ans.
        sum = a[i] + carry; //adding ith element with carry in sum.
        carry = sum / 10; //calculating carry similarly in above while loop.
        digit  = sum % 10; //getting digit.
        char ch = digit + '0'; //convert integer num to character.
        ans.push_back(ch); //pushing in ans.
        i--; //decrement i
    }
    
    while( j>=0 ){ //similarly for jth array, if elements are still remain.
        sum = b[j] + carry;
        carry = sum / 10;
        digit  = sum % 10;
        char ch = digit + '0'; //convert integer num to character.
        ans.push_back(ch);
        j--;
    }
    
    if(carry){ //at the end if any carry is present then push it in ans vector.
        ans.push_back(carry+'0');
    }
    reverse(ans.begin(),ans.end()); //reverse vector. becuase we loop from back of a,b array and pushed in front of ans.

    i=0; //This is extra step in which we are counting and removing leading zeros.
    while(ans[i] == '0') i++; //looping till leading zeros are present.
    ans.erase(0,i); //now, erase elements from 0 to i. so that we can eleminate leading zeros.
    return ans; //finally return ans.
    //or instead erasing we can return string except leading zeros by substr function.

    return ans.substr(i); //like this, returning from ith index till last.
  }

